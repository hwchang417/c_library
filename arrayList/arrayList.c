
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ArrayList.h"

ArrayList initAL(){
	ArrayList al;
	al.curr = 0;
	al.size = DEFAULT_ARRAYLIST_SIZE;
	al.data = (int *) malloc(sizeof(int) * al.size);
	return al;
}

void expandAL(ArrayList *al){
	al->size += DEFAULT_ARRAYLIST_SIZE;
	al->data = (int *) realloc(al->data, sizeof(int) * al->size);
    assert(al->data != NULL);
}

int getAL(ArrayList *al, int index){
    if(al == NULL || al->data == NULL || al->size <= index) return NULL;
	return al->data[index];
}

int getALSize(ArrayList *al){
    if(al == NULL) return;
	return al->curr;
}

void pushAL(ArrayList *al, int val){
	int ret = 1;
    if(al == NULL || al->data == NULL) return;
	if(al->size <= al->curr + 1)
		expandAL(al);
	al->data[al->curr++] = val;
}

void clearAL(ArrayList *al){
    if(al == NULL) return;
	al->curr = 0;
}

void printAL(ArrayList *al){
	int idx;
    if(al == NULL || al->data == NULL) return;
	for(idx = 0;idx < al->curr;idx++)
		printf("%d ", al->data[idx]);
	printf("\n");
}

void releaseAL(ArrayList *al){
	if(al == NULL) return;
	free(al->data);
}
