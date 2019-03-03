
#include "queue.h"
#include "../common/debug.h"


int init(Queue* s){
    s->pop_ptr = s->push_ptr = 0;
    s->capacity = DEFAULT_QUEUE_SIZE;
    s->s = (QUEUE_TYPE*)calloc(s->capacity, sizeof(QUEUE_TYPE));
    if(s->s == NULL){
        DEBUG("no enough memory to allocate\n");
        return FAILURE;
    }
    return SUCCESS;
}

int empty(Queue* s){
    return (s->pop_ptr == s->push_ptr);
}

int full(Queue* s){
    return (s->pop_ptr == (s->push_ptr + 1) % s->capacity);
}

void push(Queue* s, QUEUE_TYPE in){
    //©¹¤Uªø
    if(full(s)){
        s->capacity <<= 1;
        s->s = (QUEUE_TYPE*)realloc(s->s, sizeof(QUEUE_TYPE) * s->capacity);
    }

    s->s[s->push_ptr] = in;
    s->push_ptr = (s->push_ptr + 1) % s->capacity;
}

QUEUE_TYPE pop(Queue* s){
    if(empty(s))
        return EMPTY_QUEUE;

    int ret = s->s[s->pop_ptr];
    s->pop_ptr = (s->pop_ptr + 1) % s->capacity;

    return ret;
}


