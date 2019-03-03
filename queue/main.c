
#include <stdio.h>
#include "queue.h"

int main(){
    int index;
    Queue q;

    init(&q);

    for(index = 0;index < 1024;index++){
        push(&q, index);
    }

    while(!empty(&q)){
        printf("%d,", pop(&q));
    }
    printf("\n");

    return 0;
}

