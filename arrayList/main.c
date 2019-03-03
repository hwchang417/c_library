#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

int main(){
	const int NUM_OF_ARRAYS = 10;
	int idx;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ArrayList al = initAL();
	
	for(idx = 0;idx < NUM_OF_ARRAYS;idx++)
		pushAL(&al, arr[idx]);
	
	printAL(&al);
	
	return 0;
}