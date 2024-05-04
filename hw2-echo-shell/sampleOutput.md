## My Sample Output

```
hw2-echo-shell % ./client                 
HEADER VALUES 
  Proto Type:    PROTO_CS_FUN
  Proto Ver:     VERSION_1
  Command:       CMD_CLASS_INFO
  Direction:     DIR_RECV
  Term:          TERM_SPRING 
  Course:        CS472
  Pkt Len:       12

RECV FROM SERVER -> CS472: Welcome to computer networks

hw2-echo-shell % ./client -p "Hello World"
HEADER VALUES 
  Proto Type:    PROTO_CS_FUN
  Proto Ver:     VERSION_1
  Command:       CMD_PING_PONG
  Direction:     DIR_RECV
  Term:          TERM_SPRING 
  Course:        NONE
  Pkt Len:       24

RECV FROM SERVER -> PONG: Hello World

hw2-echo-shell % ./client -c cs472
HEADER VALUES 
  Proto Type:    PROTO_CS_FUN
  Proto Ver:     VERSION_1
  Command:       CMD_CLASS_INFO
  Direction:     DIR_RECV
  Term:          TERM_SPRING 
  Course:        cs472
  Pkt Len:       12

RECV FROM SERVER -> CS472: Welcome to computer networks

hw2-echo-shell % ./client -c cs171
HEADER VALUES 
  Proto Type:    PROTO_CS_FUN
  Proto Ver:     VERSION_1
  Command:       CMD_CLASS_INFO
  Direction:     DIR_RECV
  Term:          TERM_SPRING 
  Course:        cs171
  Pkt Len:       12

RECV FROM SERVER -> Requested Course Not Found
```