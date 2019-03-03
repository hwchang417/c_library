
#include <stdio.h>
#include "stack.h"

int main(){
    int index;
    Stack s;

    init(&s);

    for(index = 0;index < 1024;index++){
        push(&s, index);
    }

    while(!empty(&s)){
        printf("%d,", pop(&s));
    }
    printf("\n");

    return 0;
}

