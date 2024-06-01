#pragma once

#define PROG_MD_CLI     0
#define PROG_MD_SVR     1
#define DEF_PORT_NO     2080
#define FNAME_SZ        150
#define PROG_DEF_FNAME  "test.c"
#define PROG_DEF_SVR_ADDR   "127.0.0.1"

typedef struct prog_config{
    int     prog_mode;
    int     port_number;
    char    svr_ip_addr[16];
    char    file_name[128];
} prog_config;

#define FTP_PROTO_VER_1   1
#define FTP_MT_INIT       1
#define FTP_MT_DATA       2
#define FTP_MT_END        4
#define FTP_MT_ERROR      8
#define FTP_MT_INIT_ACK   (FTP_MT_INIT | 16)
#define FTP_MT_END_ACK    (FTP_MT_END | 16)

typedef struct ftp_pdu {
    int     proto_ver;
    int     mtype;
    int     seqnum;
    int     data_sz;
    char    file_name[FNAME_SZ];
    int     err_code;
} ftp_pdu;
