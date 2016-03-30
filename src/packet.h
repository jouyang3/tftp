#include <stdlib.h>

typedef uint32 HOST;

typedef struct {
    HOST sender;
    HOST recver;
    uint32 seqNum;
} CONNECTION;

