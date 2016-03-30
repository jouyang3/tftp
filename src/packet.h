#ifndef PACKET_H
#define PACKET_H

#include <stdlib.h>
#include <stdint.h>

typedef enum{
    NOOP, RRQ, WRQ, DATA, ACK, ERROR
} PACKET_TYPE;

#endif
