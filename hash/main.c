
//standard c library
#include <stdio.h>

//user-defined library
#include "hash.h"

//user define macro

//user global variable

int main(){
    Hash h;
    
    initHash(&h);
    addHash(&h, 1);
    addHash(&h, 11);
    addHash(&h, 2);
    
    printf("1 is in hash list? %d\n", existHash(&h, 1));
    printf("11 is in hash list? %d\n", existHash(&h, 11));
    printf("2 is in hash list? %d\n", existHash(&h, 2));
    printf("3 is in hash list? %d\n", existHash(&h, 3));
    
    printf("------------- remove 1 and 11 -------------\n");
    removeHash(&h, 1);
    printf("1 is in hash list? %d\n", existHash(&h, 1));
    removeHash(&h, 11);
    printf("11 is in hash list? %d\n", existHash(&h, 11));
    
    printf("------------- after all remove -------------\n");
    clearHash(&h);
    
    printf("1 is in hash list? %d\n", existHash(&h, 1));
    printf("11 is in hash list? %d\n", existHash(&h, 11));
    printf("2 is in hash list? %d\n", existHash(&h, 2));
    printf("3 is in hash list? %d\n", existHash(&h, 3));
    
    return 0;
}
