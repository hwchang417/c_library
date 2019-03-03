
#include <stdio.h>
#include "linkedList.h"

int main(){

    LinkedList list;
    init(&list);

    //push_back(&list, 1);
    //push_back(&list, 2);
    //push_back(&list, 3);

    //printf("%d, %d, %d\n",
    //       pop_back(&list),
    //       pop_back(&list),
    //       pop_back(&list));

    push_front(&list, 1);
    push_front(&list, 2);
    push_front(&list, 3);

    printf("%d, %d, %d\n",
           pop_front(&list),
           pop_front(&list),
           pop_front(&list));

    return 0;
}
