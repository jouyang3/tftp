#include <stdlib.h>
#include <sys/socket.h>

#include "server.h"

SERVER_STATUS start(SERVER_REF server, uint16_t port){
    server = (SERVER_REF) malloc(sizeof(SERVER));
    server->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server->connections = malloc(MAX_CONNECTIONS * sizeof(CONNECTION*));
    
    //Instantiates Server HOST Address
    IPv4_ADDR host_ip;
    host_ip.s_addr = INADDR_ANY;
    HOST_REF host = malloc(sizeof(SERVER));
    host->sin_port = htons(port);
    host->sin_addr = host_ip;
    server->host = host;

    if(bind(server->sockfd, (struct sockaddr *) server->host, sizeof(HOST)) < 0)
        return INIT_FAILURE;
    return INIT_SUCCESS;
}
