
#ifndef _STACK_H
#define _STACK_H

#define DEFAULT_STACK_SIZE 16

#define STACK_TYPE int
#define EMPTY_STACK -1

#include "../common/debug.h"

typedef struct stack Stack;
struct stack{
    int capacity;
    int ptr;
    STACK_TYPE* s;
};

int init(Stack* s);
int empty(Stack* s);
int full(Stack* s);
void push(Stack* s, STACK_TYPE in);
STACK_TYPE pop(Stack* s);

#endif // _STACK_H


