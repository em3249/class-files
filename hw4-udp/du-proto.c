#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <time.h>

#include "du-proto.h"

static char _dpBuffer[DP_MAX_DGRAM_SZ];
static int _debugMode = 1;

static dp_connp dpinit()
{
    dp_connp dpsession = malloc(sizeof(dp_connection));
    bzero(dpsession, sizeof(dp_connection));
    dpsession->outSockAddr.isAddrInit = false;
    dpsession->inSockAddr.isAddrInit = false;
    dpsession->outSockAddr.len = sizeof(struct sockaddr_in);
    dpsession->inSockAddr.len = sizeof(struct sockaddr_in);
    dpsession->seqNum = 0;
    dpsession->isConnected = false;
    dpsession->dbgMode = true;
    return dpsession;
}

void dpclose(dp_connp dpsession)
{
    free(dpsession);
}

int dpmaxdgram()
{
    return DP_MAX_BUFF_SZ;
}

dp_connp dpServerInit(int port)
{
    struct sockaddr_in *servaddr;
    int *sock;
    int rc;

    dp_connp dpc = dpinit();
    if (dpc == NULL)
    {
        perror("drexel protocol create failure");
        return NULL;
    }

    sock = &(dpc->udp_sock);
    servaddr = &(dpc->inSockAddr.addr);

    // Creating socket file descriptor
    if ((*sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        return NULL;
    }

    // Filling server information
    servaddr->sin_family = AF_INET; // IPv4
    servaddr->sin_addr.s_addr = INADDR_ANY;
    servaddr->sin_port = htons(port);

    // Set socket options so that we dont have to wait for ports held by OS
    // if (setsockopt(*sock, SOL_SOCKET, SO_REUSEPORT, &(int){1}, sizeof(int)) < 0){
    //     perror("setsockopt(SO_REUSEADDR) failed");
    //     close(*sock);
    //     return NULL;
    // }
    if (setsockopt(*sock, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0)
    {
        perror("setsockopt(SO_REUSEADDR) failed");
        close(*sock);
        return NULL;
    }
    if ((rc = bind(*sock, (const struct sockaddr *)servaddr,
                   dpc->inSockAddr.len)) < 0)
    {
        perror("bind failed");
        close(*sock);
        return NULL;
    }

    dpc->inSockAddr.isAddrInit = true;
    dpc->outSockAddr.len = sizeof(struct sockaddr_in);
    return dpc;
}

dp_connp dpClientInit(char *addr, int port)
{
    struct sockaddr_in *servaddr;
    int *sock;

    dp_connp dpc = dpinit();
    if (dpc == NULL)
    {
        perror("drexel protocol create failure");
        return NULL;
    }

    sock = &(dpc->udp_sock);
    servaddr = &(dpc->outSockAddr.addr);

    // Creating socket file descriptor
    if ((*sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        return NULL;
    }

    // Filling server information
    servaddr->sin_family = AF_INET;
    servaddr->sin_port = htons(port);
    servaddr->sin_addr.s_addr = inet_addr(addr);
    dpc->outSockAddr.len = sizeof(struct sockaddr_in);
    dpc->outSockAddr.isAddrInit = true;

    // The inbound address is the same as the outbound address
    memcpy(&dpc->inSockAddr, &dpc->outSockAddr, sizeof(dpc->outSockAddr));

    return dpc;
}

int dprecv(dp_connp dp, void *buff, int buff_sz)
{
    int totalReceived = 0;
    char *rPtr = buff;

    do
    {
        int amount_received = dprecvdgram(dp, _dpBuffer, sizeof(_dpBuffer));
        if (amount_received == DP_CONNECTION_CLOSED)
            return DP_CONNECTION_CLOSED;

        dp_pdu *pduPtr = (dp_pdu *)_dpBuffer;
        void *dataPtr = (_dpBuffer + sizeof(dp_pdu));

        if (totalReceived + pduPtr->dgram_sz > buff_sz)
            return DP_BUFF_OVERSIZED;

        memcpy(rPtr, dataPtr, pduPtr->dgram_sz);
        rPtr += pduPtr->dgram_sz;
        totalReceived += pduPtr->dgram_sz;

        if (IS_MT_FRAGMENT(pduPtr->mtype))
        {
            // handle fragment
        }

    } while (IS_MT_FRAGMENT(((dp_pdu *)_dpBuffer)->mtype));

    return totalReceived;
}

static int dprecvdgram(dp_connp dp, void *buff, int buff_sz)
{
    int bytesIn = 0;
    int errCode = DP_NO_ERROR;

    if (buff_sz > DP_MAX_DGRAM_SZ)
        return DP_BUFF_OVERSIZED;

    bytesIn = dprecvraw(dp, buff, buff_sz);

    if (bytesIn < sizeof(dp_pdu))
        return DP_ERROR_BAD_DGRAM;

    dp_pdu inPdu;
    memcpy(&inPdu, buff, sizeof(dp_pdu));
    if (inPdu.dgram_sz > buff_sz)
        return DP_BUFF_UNDERSIZED;

    if (errCode == DP_NO_ERROR)
    {
        dp->seqNum += (inPdu.dgram_sz == 0) ? 1 : inPdu.dgram_sz;
    }
    else
    {
        dp->seqNum++;
    }

    dp_pdu outPdu;
    outPdu.proto_ver = DP_PROTO_VER_1;
    outPdu.dgram_sz = 0;
    outPdu.seqnum = dp->seqNum;
    outPdu.err_num = errCode;

    if (errCode != DP_NO_ERROR)
    {
        outPdu.mtype = DP_MT_ERROR;
        dpsendraw(dp, &outPdu, sizeof(dp_pdu));
        return DP_ERROR_PROTOCOL;
    }

    switch (inPdu.mtype)
    {
    case DP_MT_SND:
        outPdu.mtype = DP_MT_SNDACK;
        dpsendraw(dp, &outPdu, sizeof(dp_pdu));
        break;
    case DP_MT_SNDFRAG:
        outPdu.mtype = DP_MT_SNDFRAGACK;
        dpsendraw(dp, &outPdu, sizeof(dp_pdu));
        break;
    case DP_MT_CLOSE:
        outPdu.mtype = DP_MT_CLOSEACK;
        dpsendraw(dp, &outPdu, sizeof(dp_pdu));
        dpclose(dp);
        return DP_CONNECTION_CLOSED;
    default:
        printf("ERROR: Unexpected or bad mtype in header %d\n", inPdu.mtype);
        return DP_ERROR_PROTOCOL;
    }

    return bytesIn;
}

static int dprecvraw(dp_connp dp, void *buff, int buff_sz)
{
    int bytes = 0;

    if (!dp->inSockAddr.isAddrInit)
    {
        perror("dprecv: dp connection not setup properly - cli struct not init");
        return -1;
    }

    bytes = recvfrom(dp->udp_sock, (char *)buff, buff_sz,
                     MSG_WAITALL, (struct sockaddr *)&(dp->outSockAddr.addr),
                     &(dp->outSockAddr.len));

    if (bytes < 0)
    {
        perror("dprecv: received error from recvfrom()");
        return -1;
    }
    dp->outSockAddr.isAddrInit = true;

    // some helper code if you want to do debugging
    if (bytes > sizeof(dp_pdu))
    {
        if (false)
        { // just diabling for now
            dp_pdu *inPdu = buff;
            char *payload = (char *)buff + sizeof(dp_pdu);
            printf("DATA : %.*s\n", inPdu->dgram_sz, payload);
        }
    }

    dp_pdu *inPdu = buff;
    print_in_pdu(inPdu);

    // return the number of bytes received
    return bytes;
}

int dpsend(dp_connp dp, void *sbuff, int sbuff_sz)
{
    int totalToSend = sbuff_sz;
    char *sptr = sbuff;

    while (totalToSend > 0)
    {
        int amountToSend = totalToSend > DP_MAX_BUFF_SZ ? DP_MAX_BUFF_SZ : totalToSend;
        int sent = dpsenddgram(dp, sptr, amountToSend);
        if (sent < 0)
        {
            return sent; // Handle error
        }
        totalToSend -= sent;
        sptr += sent;
    }

    return sbuff_sz;
}

static int dpsenddgram(dp_connp dp, void *sbuff, int sbuff_sz)
{
    int bytesOut = 0;
    if (!dp->outSockAddr.isAddrInit)
    {
        perror("dpsend:dp connection not setup properly");
        return DP_ERROR_GENERAL;
    }

    if (sbuff_sz > DP_MAX_BUFF_SZ)
    {
        return DP_BUFF_UNDERSIZED;
    }

    dp_pdu *outPdu = (dp_pdu *)_dpBuffer;
    int sndSz = sbuff_sz;
    outPdu->proto_ver = DP_PROTO_VER_1;
    outPdu->mtype = (sbuff_sz > DP_MAX_BUFF_SZ) ? DP_MT_SNDFRAG : DP_MT_SND;
    outPdu->dgram_sz = sndSz;
    outPdu->seqnum = dp->seqNum;

    memcpy((_dpBuffer + sizeof(dp_pdu)), sbuff, sndSz);

    int totalSendSz = outPdu->dgram_sz + sizeof(dp_pdu);
    bytesOut = dpsendraw(dp, _dpBuffer, totalSendSz);

    if (bytesOut != totalSendSz)
    {
        printf("Warning send %d, but expected %d!\n", bytesOut, totalSendSz);
    }

    if (outPdu->dgram_sz == 0)
        dp->seqNum++;
    else
        dp->seqNum += outPdu->dgram_sz;

    dp_pdu inPdu = {0};
    int bytesIn = dprecvraw(dp, &inPdu, sizeof(dp_pdu));
    if ((bytesIn < sizeof(dp_pdu)) && (inPdu.mtype != ((sbuff_sz > DP_MAX_BUFF_SZ) ? DP_MT_SNDFRAGACK : DP_MT_SNDACK)))
    {
        printf("Expected SND/ACK but got a different mtype %d\n", inPdu.mtype);
    }

    return bytesOut - sizeof(dp_pdu);
}

static int dpsendraw(dp_connp dp, void *sbuff, int sbuff_sz)
{
    int bytesOut = 0;
    // dp_pdu *pdu = sbuff;

    if (!dp->outSockAddr.isAddrInit)
    {
        perror("dpsendraw:dp connection not setup properly");
        return -1;
    }

    dp_pdu *outPdu = sbuff;
    bytesOut = sendto(dp->udp_sock, (const char *)sbuff, sbuff_sz,
                      0, (const struct sockaddr *)&(dp->outSockAddr.addr),
                      dp->outSockAddr.len);

    print_out_pdu(outPdu);

    return bytesOut;
}

int dplisten(dp_connp dp)
{
    int sndSz, rcvSz;

    if (!dp->inSockAddr.isAddrInit)
    {
        perror("dplisten:dp connection not setup properly - cli struct not init");
        return DP_ERROR_GENERAL;
    }

    dp_pdu pdu = {0};

    printf("Waiting for a connection...\n");
    rcvSz = dprecvraw(dp, &pdu, sizeof(pdu));
    if (rcvSz != sizeof(pdu))
    {
        perror("dplisten:The wrong number of bytes were received");
        return DP_ERROR_GENERAL;
    }

    pdu.mtype = DP_MT_CNTACK;
    dp->seqNum = pdu.seqnum + 1;
    pdu.seqnum = dp->seqNum;

    sndSz = dpsendraw(dp, &pdu, sizeof(pdu));

    if (sndSz != sizeof(pdu))
    {
        perror("dplisten:The wrong number of bytes were sent");
        return DP_ERROR_GENERAL;
    }
    dp->isConnected = true;
    // For non data transmissions, ACK of just control data increase seq # by one
    printf("Connection established OK!\n");

    return true;
}

int dpconnect(dp_connp dp)
{

    int sndSz, rcvSz;

    if (!dp->outSockAddr.isAddrInit)
    {
        perror("dpconnect:dp connection not setup properly - svr struct not init");
        return DP_ERROR_GENERAL;
    }

    dp_pdu pdu = {0};
    pdu.mtype = DP_MT_CONNECT;
    pdu.seqnum = dp->seqNum;
    pdu.dgram_sz = 0;

    sndSz = dpsendraw(dp, &pdu, sizeof(pdu));
    if (sndSz != sizeof(dp_pdu))
    {
        perror("dpconnect:Wrong about of connection data sent");
        return -1;
    }

    rcvSz = dprecvraw(dp, &pdu, sizeof(pdu));
    if (rcvSz != sizeof(dp_pdu))
    {
        perror("dpconnect:Wrong about of connection data received");
        return -1;
    }
    if (pdu.mtype != DP_MT_CNTACK)
    {
        perror("dpconnect:Expected CNTACT Message but didnt get it");
        return -1;
    }

    // For non data transmissions, ACK of just control data increase seq # by one
    dp->seqNum++;
    dp->isConnected = true;
    printf("Connection established OK!\n");

    return true;
}

int dpdisconnect(dp_connp dp)
{

    int sndSz, rcvSz;

    dp_pdu pdu = {0};
    pdu.proto_ver = DP_PROTO_VER_1;
    pdu.mtype = DP_MT_CLOSE;
    pdu.seqnum = dp->seqNum;
    pdu.dgram_sz = 0;

    sndSz = dpsendraw(dp, &pdu, sizeof(pdu));
    if (sndSz != sizeof(dp_pdu))
    {
        perror("dpdisconnect:Wrong about of connection data sent");
        return DP_ERROR_GENERAL;
    }

    rcvSz = dprecvraw(dp, &pdu, sizeof(pdu));
    if (rcvSz != sizeof(dp_pdu))
    {
        perror("dpdisconnect:Wrong about of connection data received");
        return DP_ERROR_GENERAL;
    }
    if (pdu.mtype != DP_MT_CLOSEACK)
    {
        perror("dpdisconnect:Expected CNTACT Message but didnt get it");
        return DP_ERROR_GENERAL;
    }
    // For non data transmissions, ACK of just control data increase seq # by one
    dpclose(dp);

    return DP_CONNECTION_CLOSED;
}

void *dp_prepare_send(dp_pdu *pdu_ptr, void *buff, int buff_sz)
{
    if (buff_sz < sizeof(dp_pdu))
    {
        perror("Expected CNTACT Message but didnt get it");
        return NULL;
    }
    bzero(buff, buff_sz);
    memcpy(buff, pdu_ptr, sizeof(dp_pdu));

    return buff + sizeof(dp_pdu);
}

//// MISC HELPERS
void print_out_pdu(dp_pdu *pdu)
{
    if (_debugMode != 1)
        return;
    printf("PDU DETAILS ===>  [OUT]\n");
    print_pdu_details(pdu);
}
void print_in_pdu(dp_pdu *pdu)
{
    if (_debugMode != 1)
        return;
    printf("===> PDU DETAILS  [IN]\n");
    print_pdu_details(pdu);
}
static void print_pdu_details(dp_pdu *pdu)
{

    printf("\tVersion:  %d\n", pdu->proto_ver);
    printf("\tMsg Type: %s\n", pdu_msg_to_string(pdu));
    printf("\tMsg Size: %d\n", pdu->dgram_sz);
    printf("\tSeq Numb: %d\n", pdu->seqnum);
    printf("\n");
}

static char *pdu_msg_to_string(dp_pdu *pdu)
{
    switch (pdu->mtype)
    {
    case DP_MT_ACK:
        return "ACK";
    case DP_MT_SND:
        return "SEND";
    case DP_MT_CONNECT:
        return "CONNECT";
    case DP_MT_CLOSE:
        return "CLOSE";
    case DP_MT_NACK:
        return "NACK";
    case DP_MT_SNDACK:
        return "SEND/ACK";
    case DP_MT_CNTACK:
        return "CONNECT/ACK";
    case DP_MT_CLOSEACK:
        return "CLOSE/ACK";
    case DP_MT_SNDFRAG:
        return "SEND/FRAGMENT";
    case DP_MT_SNDFRAGACK:
        return "SEND/FRAGMENT/ACK";
    default:
        return "***UNKNOWN***";
    }
}

/*
 *  This is a helper for testing if you want to inject random errors from
 *  time to time. It take a threshold number as a paramter and behaves as
 *  follows:
 *      if threshold is < 1 it always returns FALSE or zero
 *      if threshold is > 99 it always returns TRUE or 1
 *      if (1 <= threshold <= 99) it generates a random number between
 *          1..100 and if the random number is less than the threshold
 *          it returns TRUE, else it returns false
 *
 *  Example: dprand(50) is a coin flip
 *              dprand(25) will return true 25% of the time
 *              dprand(99) will return true 99% of the time
 */
int dprand(int threshold)
{

    if (threshold < 1)
        return 0;
    if (threshold > 99)
        return 1;
    // initialize randome number seed
    srand(time(0));

    int rndInRange = (rand() % (100 - 1 + 1)) + 1;
    if (threshold < rndInRange)
        return 1;
    else
        return 0;
}
