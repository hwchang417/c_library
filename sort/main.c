#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"
#include "../arrayList/arrayList.h"
#define NUM_OF_SORT_METHODS 8

/* test program for sorting */

int main(){
    int i, j, k, m, *rarray;
    const int NUM_OF_SAMPLES = 3;
	const int SIZE[] = {RAND_MAX + 1, (RAND_MAX + 1), (RAND_MAX + 1)};
	const int AVERAGE_TIME = 10;
	
	void (*sort[NUM_OF_SORT_METHODS])(TYPE *, int, COMPARE cmp)
            = { selectSort, bubbleSort, insertSort, quickSort, mergeSort, treeSort, heapSort, radixSort};
	long long int total_time;
	clock_t start, end;
	FILE* fout;
	
	srand(time(NULL));
	
	printf("1.[SelectSort]\n");
	printf("2.[BubbleSort]\n");
	printf("3.[InsertSort]\n");
	printf("4.[QuickSort ]\n");
	printf("5.[MergeSort ]\n");
	printf("6.[TreeSort  ]\n");
	printf("7.[HeapSort  ]\n");
	printf("8.[RadixSort  ]\n");
	
	#ifdef _OUTPUT_TEST
    fout = fopen("benchmark.csv", "w");
	fprintf(fout, "NUM_OF_SAMPLES,SelectSort,BubbleSort,InsertSort,QuickSort,MergeSort,TreeSort,HeapSort,RadixSort\n");
	#endif
	
	for(i = 0;i < NUM_OF_SAMPLES;i++){
		#ifdef _OUTPUT_TEST
		fprintf(fout, "%d,", SIZE[i]);
		#endif
		
        // initialize input data
        rarray = (int *) malloc(sizeof(int) * SIZE[i]);
        if(rarray == NULL) break;
        
		for(k = 0;k < NUM_OF_SORT_METHODS;k++){
			
			total_time = 0;
			for(m = 0;m < AVERAGE_TIME;m++){
				// randomize input data
				for(j = 0;j < SIZE[i];j++) rarray[j] = j;
				for(j = 0;j < SIZE[i];j++) swap(&rarray[rand()], &rarray[rand()]);
				
				start = clock();
				sort[k](rarray, SIZE[i], greater);
				end = clock();
				total_time += (end - start);
				printf("SIZE=%d, method%d, th=%d, time=%.3f\n", SIZE[i], k, m, (float)(end - start) / CLOCKS_PER_SEC);
				
				// verify the sorted result 
				int cnt = 0;
				for(j = 0;j < SIZE[i];j++)
					if(rarray[j] != j)
                        cnt++;
			}
			printf("%.3f\n", (float)total_time / CLOCKS_PER_SEC / AVERAGE_TIME);
			
			#ifdef _OUTPUT_TEST
			fprintf(fout, "%.3f,", (float)total_time / CLOCKS_PER_SEC / AVERAGE_TIME);
			#endif
		}
		
        free(rarray);
		#ifdef _OUTPUT_TEST
		fprintf(fout, "\n");
		#endif
	}
    #ifdef _OUTPUT_TEST
    fclose(fout);
    #endif
	
	return 0;
}
