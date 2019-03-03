
#ifndef _QUEUE_H
#define _QUEUE_H

#define DEFAULT_QUEUE_SIZE 16

#define QUEUE_TYPE int
#define EMPTY_QUEUE -1

#include "../common/debug.h"

typedef struct queue Queue;
struct queue{
    int capacity;
    int push_ptr;
    int pop_ptr;
    QUEUE_TYPE* s;
};

int init(Queue* s);
int empty(Queue* s);
int full(Queue* s);
void push(Queue* s, QUEUE_TYPE in);
QUEUE_TYPE pop(Queue* s);

#endif // _QUEUE_H


