#include <stdlib.h>

#ifndef BLOCK_SIZE
#define BLOCK_SIZE 512
#endif

typedef enum{
    ACK, NACK, LOCK, SEND
} EVENT_TYPE;

typedef struct {
    EVENT_TYPE type;
    void* handler;
    void* payload;
} EVENT;

typedef struct {
    EVENT* eventQueue;
    uint32 queueSize;
} GEL;

