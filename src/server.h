#ifndef SERVER_H
#define SERVER_H

#include <stdlib.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#ifndef MAX_CONNECTIONS
#define MAX_CONNECTIONS 256
#endif

typedef enum{
    INIT_SUCCESS, INIT_FAILURE
} SERVER_STATUS;

typedef struct{
    uint32_t s_addr;
} IPv4_ADDR;

typedef struct{
    sa_family_t sin_family;
    in_port_t sin_port;
    IPv4_ADDR sin_addr;
} HOST, *HOST_REF; 

typedef struct {
    HOST_REF client;
    uint32_t seqNum;
    int sockfd;
} CONNECTION, *CONNECTION_REF;

typedef struct{
    int sockfd;
    HOST_REF host;
    CONNECTION_REF connections;
} SERVER,*SERVER_REF;

SERVER_STATUS start(SERVER_REF server, uint16_t port);

#endif
