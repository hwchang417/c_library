
#include "stack.h"
#include "../common/debug.h"


int init(Stack* s){
    s->ptr = 0;
    s->capacity = DEFAULT_STACK_SIZE;
    s->s = (STACK_TYPE*)calloc(s->capacity, sizeof(STACK_TYPE));
    if(s->s == NULL){
        DEBUG("Stack: no enough memory to allocate\n");
        return FAILURE;
    }
    return SUCCESS;
}

int empty(Stack* s){
    return (s->ptr == 0);
}

int full(Stack* s){
    return (s->ptr == s->capacity - 1);
}

void push(Stack* s, STACK_TYPE in){
    if(full(s)){
        s->capacity <<= 1;
        s->s = (STACK_TYPE*)realloc(s->s, sizeof(STACK_TYPE) * s->capacity);
    }

    s->s[s->ptr++] = in;
}

STACK_TYPE pop(Stack* s){
    if(empty(s))
        return EMPTY_STACK;
    int ret = s->s[s->ptr - 1];
    s->ptr--;
    return ret;
}


