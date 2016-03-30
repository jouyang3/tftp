#ifndef GEL_H
#define GEL_H

#include <stdlib.h>
#include <stdint.h>

#ifndef BLOCK_SIZE
#define BLOCK_SIZE 512
#endif

typedef enum{
    RECEIVE, LOCK, SEND
} EVENT_TYPE;

typedef struct {
    EVENT_TYPE type;
    void* handler;
    void* payload;
} EVENT;

typedef struct {
    EVENT* eventQueue;
    uint32_t queueSize;
} GEL;

#endif
