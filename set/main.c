#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "set.h"

int main(){
	const int ARRAY_SIZE = 5, SEARCH_ARRAY_SIZE = 10;
	int i, arr[] = {1, 2, 3, 4, 5}, searchArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Set* s = initSet();
	
	for(i = 0;i < ARRAY_SIZE;i++)
		addSet(s, arr[i]);
    
    removeSet(s, 1);
    removeSet(s, 3);
    removeSet(s, 4);
    removeSet(s, 5);
    
	for(i = 0;i < SEARCH_ARRAY_SIZE;i++)
		printf("Is %d existing in set? %d\n", searchArr[i], isExistSet(s, searchArr[i]) != 0);
	
	releaseSet(s);
	
	return 0;
}

