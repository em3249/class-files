// Frame (42 bytes)
static unsigned char pkt18027[42] = {
0xac, 0xc9, 0x06, 0x12, 0x71, 0x52, 0xb0, 0xb9, // ....qR..
0x8a, 0xd7, 0x93, 0x5c, 0x08, 0x06, 0x00, 0x01, // ...\....
0x08, 0x00, 0x06, 0x04, 0x00, 0x02, 0xb0, 0xb9, // ........
0x8a, 0xd7, 0x93, 0x5c, 0xc0, 0xa8, 0x00, 0x01, // ...\....
0xac, 0xc9, 0x06, 0x12, 0x71, 0x52, 0xc0, 0xa8, // ....qR..
0x00, 0x41                                      // .A
};
/*
Frame 18027: 42 bytes on wire (336 bits), 42 bytes captured (336 bits) on interface en0, id 0
    Section number: 1
    Interface id: 0 (en0)
        Interface name: en0
        Interface description: Wi-Fi
    Encapsulation type: Ethernet (1)
    Arrival Time: Apr 19, 2024 23:19:08.156300000 EDT
    UTC Arrival Time: Apr 20, 2024 03:19:08.156300000 UTC
    Epoch Arrival Time: 1713583148.156300000
    [Time shift for this packet: 0.000000000 seconds]
    [Time delta from previous captured frame: 0.373104000 seconds]
    [Time delta from previous displayed frame: 0.000000000 seconds]
    [Time since reference or first frame: 68.429378000 seconds]
    Frame Number: 18027
    Frame Length: 42 bytes (336 bits)
    Capture Length: 42 bytes (336 bits)
    [Frame is marked: False]
    [Frame is ignored: False]
    [Protocols in frame: eth:ethertype:arp]
    [Coloring Rule Name: ARP]
    [Coloring Rule String: arp]
Ethernet II, Src: Netgear_d7:93:5c (b0:b9:8a:d7:93:5c), Dst: Apple_12:71:52 (ac:c9:06:12:71:52)
    Destination: Apple_12:71:52 (ac:c9:06:12:71:52)
        Address: Apple_12:71:52 (ac:c9:06:12:71:52)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source: Netgear_d7:93:5c (b0:b9:8a:d7:93:5c)
        Address: Netgear_d7:93:5c (b0:b9:8a:d7:93:5c)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Type: ARP (0x0806)
Address Resolution Protocol (reply)
    Hardware type: Ethernet (1)
    Protocol type: IPv4 (0x0800)
    Hardware size: 6
    Protocol size: 4
    Opcode: reply (2)
    Sender MAC address: Netgear_d7:93:5c (b0:b9:8a:d7:93:5c)
    Sender IP address: 192.168.0.1
    Target MAC address: Apple_12:71:52 (ac:c9:06:12:71:52)
    Target IP address: 192.168.0.65
*/


// Frame (70 bytes)
static unsigned char pkt19299[70] = {
0xac, 0xc9, 0x06, 0x12, 0x71, 0x52, 0x00, 0x01, // ....qR..
0x5c, 0x7d, 0x02, 0x46, 0x08, 0x00, 0x45, 0x00, // \}.F..E.
0x00, 0x38, 0x07, 0xcf, 0x00, 0x00, 0x40, 0x01, // .8....@.
0xf1, 0x63, 0xc0, 0xa8, 0x00, 0x01, 0xc0, 0xa8, // .c......
0x00, 0x41, 0x0b, 0x00, 0x3c, 0x8f, 0x00, 0x00, // .A..<...
0x00, 0x00, 0x45, 0x00, 0x00, 0x54, 0xa0, 0x0a, // ..E..T..
0x00, 0x00, 0x01, 0x01, 0xa1, 0x4c, 0xc0, 0xa8, // .....L..
0x00, 0x41, 0x8e, 0xfb, 0x28, 0x6e, 0x08, 0x00, // .A..(n..
0xd7, 0x32, 0xd9, 0x3c, 0x00, 0x01              // .2.<..
};
/*
Frame 19299: 70 bytes on wire (560 bits), 70 bytes captured (560 bits) on interface en0, id 0
    Section number: 1
    Interface id: 0 (en0)
        Interface name: en0
        Interface description: Wi-Fi
    Encapsulation type: Ethernet (1)
    Arrival Time: Apr 19, 2024 23:20:45.862293000 EDT
    UTC Arrival Time: Apr 20, 2024 03:20:45.862293000 UTC
    Epoch Arrival Time: 1713583245.862293000
    [Time shift for this packet: 0.000000000 seconds]
    [Time delta from previous captured frame: 0.004329000 seconds]
    [Time delta from previous displayed frame: 0.026037000 seconds]
    [Time since reference or first frame: 166.135371000 seconds]
    Frame Number: 19299
    Frame Length: 70 bytes (560 bits)
    Capture Length: 70 bytes (560 bits)
    [Frame is marked: False]
    [Frame is ignored: False]
    [Protocols in frame: eth:ethertype:ip:icmp:ip:icmp]
    [Coloring Rule Name: ICMP errors]
    [Coloring Rule String: icmp.type in { 3..5, 11 } || icmpv6.type in { 1..4 }]
Ethernet II, Src: Cadant_7d:02:46 (00:01:5c:7d:02:46), Dst: Apple_12:71:52 (ac:c9:06:12:71:52)
    Destination: Apple_12:71:52 (ac:c9:06:12:71:52)
        Address: Apple_12:71:52 (ac:c9:06:12:71:52)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source: Cadant_7d:02:46 (00:01:5c:7d:02:46)
        Address: Cadant_7d:02:46 (00:01:5c:7d:02:46)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 192.168.0.1, Dst: 192.168.0.65
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
        0000 00.. = Differentiated Services Codepoint: Default (0)
        .... ..00 = Explicit Congestion Notification: Not ECN-Capable Transport (0)
    Total Length: 56
    Identification: 0x07cf (1999)
    000. .... = Flags: 0x0
        0... .... = Reserved bit: Not set
        .0.. .... = Don't fragment: Not set
        ..0. .... = More fragments: Not set
    ...0 0000 0000 0000 = Fragment Offset: 0
    Time to Live: 64
    Protocol: ICMP (1)
    Header Checksum: 0xf163 [validation disabled]
    [Header checksum status: Unverified]
    Source Address: 192.168.0.1
    Destination Address: 192.168.0.65
Internet Control Message Protocol
    Type: 11 (Time-to-live exceeded)
    Code: 0 (Time to live exceeded in transit)
    Checksum: 0x3c8f [correct]
    [Checksum Status: Good]
    Unused: 00000000
    Internet Protocol Version 4, Src: 192.168.0.65, Dst: 142.251.40.110
        0100 .... = Version: 4
        .... 0101 = Header Length: 20 bytes (5)
        Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
            0000 00.. = Differentiated Services Codepoint: Default (0)
            .... ..00 = Explicit Congestion Notification: Not ECN-Capable Transport (0)
        Total Length: 84
        Identification: 0xa00a (40970)
        000. .... = Flags: 0x0
            0... .... = Reserved bit: Not set
            .0.. .... = Don't fragment: Not set
            ..0. .... = More fragments: Not set
        ...0 0000 0000 0000 = Fragment Offset: 0
        Time to Live: 1
            [Expert Info (Note/Sequence): "Time To Live" only 1]
                ["Time To Live" only 1]
                [Severity level: Note]
                [Group: Sequence]
        Protocol: ICMP (1)
        Header Checksum: 0xa14c [validation disabled]
        [Header checksum status: Unverified]
        Source Address: 192.168.0.65
        Destination Address: 142.251.40.110
    Internet Control Message Protocol
        Type: 8 (Echo (ping) request)
        Code: 0
        Checksum: 0xd732 [unverified] [in ICMP error packet]
        [Checksum Status: Unverified]
        Identifier (BE): 55612 (0xd93c)
        Identifier (LE): 15577 (0x3cd9)
        Sequence Number (BE): 1 (0x0001)
        Sequence Number (LE): 256 (0x0100)
*/


// Frame (98 bytes)
static unsigned char pkt19573[98] = {
0xb0, 0xb9, 0x8a, 0xd7, 0x93, 0x5c, 0xac, 0xc9, // .....\..
0x06, 0x12, 0x71, 0x52, 0x08, 0x00, 0x45, 0x00, // ..qR..E.
0x00, 0x54, 0xbb, 0x8e, 0x00, 0x00, 0x40, 0x01, // .T....@.
0x46, 0xc8, 0xc0, 0xa8, 0x00, 0x41, 0x8e, 0xfb, // F....A..
0x28, 0x6e, 0x08, 0x00, 0xe5, 0x07, 0xf8, 0x3c, // (n.....<
0x00, 0x02, 0x66, 0x23, 0x34, 0x9d, 0x00, 0x00, // ..f#4...
0x94, 0xf5, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, // ........
0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, // ........
0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, // ........
0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, // .. !"#$%
0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, // &'()*+,-
0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, // ./012345
0x36, 0x37                                      // 67
};
/*
Frame 19573: 98 bytes on wire (784 bits), 98 bytes captured (784 bits) on interface en0, id 0
    Section number: 1
    Interface id: 0 (en0)
        Interface name: en0
        Interface description: Wi-Fi
    Encapsulation type: Ethernet (1)
    Arrival Time: Apr 19, 2024 23:21:01.038349000 EDT
    UTC Arrival Time: Apr 20, 2024 03:21:01.038349000 UTC
    Epoch Arrival Time: 1713583261.038349000
    [Time shift for this packet: 0.000000000 seconds]
    [Time delta from previous captured frame: 0.983943000 seconds]
    [Time delta from previous displayed frame: 0.983943000 seconds]
    [Time since reference or first frame: 181.311427000 seconds]
    Frame Number: 19573
    Frame Length: 98 bytes (784 bits)
    Capture Length: 98 bytes (784 bits)
    [Frame is marked: False]
    [Frame is ignored: False]
    [Protocols in frame: eth:ethertype:ip:icmp:data]
    [Coloring Rule Name: ICMP]
    [Coloring Rule String: icmp || icmpv6]
Ethernet II, Src: Apple_12:71:52 (ac:c9:06:12:71:52), Dst: Netgear_d7:93:5c (b0:b9:8a:d7:93:5c)
    Destination: Netgear_d7:93:5c (b0:b9:8a:d7:93:5c)
        Address: Netgear_d7:93:5c (b0:b9:8a:d7:93:5c)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source: Apple_12:71:52 (ac:c9:06:12:71:52)
        Address: Apple_12:71:52 (ac:c9:06:12:71:52)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 192.168.0.65, Dst: 142.251.40.110
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
        0000 00.. = Differentiated Services Codepoint: Default (0)
        .... ..00 = Explicit Congestion Notification: Not ECN-Capable Transport (0)
    Total Length: 84
    Identification: 0xbb8e (48014)
    000. .... = Flags: 0x0
        0... .... = Reserved bit: Not set
        .0.. .... = Don't fragment: Not set
        ..0. .... = More fragments: Not set
    ...0 0000 0000 0000 = Fragment Offset: 0
    Time to Live: 64
    Protocol: ICMP (1)
    Header Checksum: 0x46c8 [validation disabled]
    [Header checksum status: Unverified]
    Source Address: 192.168.0.65
    Destination Address: 142.251.40.110
Internet Control Message Protocol
    Type: 8 (Echo (ping) request)
    Code: 0
    Checksum: 0xe507 [correct]
    [Checksum Status: Good]
    Identifier (BE): 63548 (0xf83c)
    Identifier (LE): 15608 (0x3cf8)
    Sequence Number (BE): 2 (0x0002)
    Sequence Number (LE): 512 (0x0200)
    [Response frame: 19574]
    Timestamp from icmp data: Apr 19, 2024 23:21:01.038133000 EDT
    [Timestamp from icmp data (relative): 0.000216000 seconds]
    Data (48 bytes)
        Data: 08090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f3031323334353637
        [Length: 48]
*/

// Frame (98 bytes)
static unsigned char pkt19574[98] = {
0xac, 0xc9, 0x06, 0x12, 0x71, 0x52, 0xb0, 0xb9, // ....qR..
0x8a, 0xd7, 0x93, 0x5c, 0x08, 0x00, 0x45, 0x00, // ...\..E.
0x00, 0x54, 0x00, 0x00, 0x00, 0x00, 0x3a, 0x01, // .T....:.
0x08, 0x57, 0x8e, 0xfb, 0x28, 0x6e, 0xc0, 0xa8, // .W..(n..
0x00, 0x41, 0x00, 0x00, 0xed, 0x07, 0xf8, 0x3c, // .A.....<
0x00, 0x02, 0x66, 0x23, 0x34, 0x9d, 0x00, 0x00, // ..f#4...
0x94, 0xf5, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, // ........
0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, // ........
0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, // ........
0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, // .. !"#$%
0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, // &'()*+,-
0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, // ./012345
0x36, 0x37                                      // 67
};
/*
Frame 19574: 98 bytes on wire (784 bits), 98 bytes captured (784 bits) on interface en0, id 0
    Section number: 1
    Interface id: 0 (en0)
        Interface name: en0
        Interface description: Wi-Fi
    Encapsulation type: Ethernet (1)
    Arrival Time: Apr 19, 2024 23:21:01.061721000 EDT
    UTC Arrival Time: Apr 20, 2024 03:21:01.061721000 UTC
    Epoch Arrival Time: 1713583261.061721000
    [Time shift for this packet: 0.000000000 seconds]
    [Time delta from previous captured frame: 0.023372000 seconds]
    [Time delta from previous displayed frame: 0.023372000 seconds]
    [Time since reference or first frame: 181.334799000 seconds]
    Frame Number: 19574
    Frame Length: 98 bytes (784 bits)
    Capture Length: 98 bytes (784 bits)
    [Frame is marked: False]
    [Frame is ignored: False]
    [Protocols in frame: eth:ethertype:ip:icmp:data]
    [Coloring Rule Name: ICMP]
    [Coloring Rule String: icmp || icmpv6]
Ethernet II, Src: Netgear_d7:93:5c (b0:b9:8a:d7:93:5c), Dst: Apple_12:71:52 (ac:c9:06:12:71:52)
    Destination: Apple_12:71:52 (ac:c9:06:12:71:52)
        Address: Apple_12:71:52 (ac:c9:06:12:71:52)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source: Netgear_d7:93:5c (b0:b9:8a:d7:93:5c)
        Address: Netgear_d7:93:5c (b0:b9:8a:d7:93:5c)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 142.251.40.110, Dst: 192.168.0.65
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
        0000 00.. = Differentiated Services Codepoint: Default (0)
        .... ..00 = Explicit Congestion Notification: Not ECN-Capable Transport (0)
    Total Length: 84
    Identification: 0x0000 (0)
    000. .... = Flags: 0x0
        0... .... = Reserved bit: Not set
        .0.. .... = Don't fragment: Not set
        ..0. .... = More fragments: Not set
    ...0 0000 0000 0000 = Fragment Offset: 0
    Time to Live: 58
    Protocol: ICMP (1)
    Header Checksum: 0x0857 [validation disabled]
    [Header checksum status: Unverified]
    Source Address: 142.251.40.110
    Destination Address: 192.168.0.65
Internet Control Message Protocol
    Type: 0 (Echo (ping) reply)
    Code: 0
    Checksum: 0xed07 [correct]
    [Checksum Status: Good]
    Identifier (BE): 63548 (0xf83c)
    Identifier (LE): 15608 (0x3cf8)
    Sequence Number (BE): 2 (0x0002)
    Sequence Number (LE): 512 (0x0200)
    [Request frame: 19573]
    [Response time: 23.372 ms]
    Timestamp from icmp data: Apr 19, 2024 23:21:01.038133000 EDT
    [Timestamp from icmp data (relative): 0.023588000 seconds]
    Data (48 bytes)
        Data: 08090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f3031323334353637
        [Length: 48]
*/

