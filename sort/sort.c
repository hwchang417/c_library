#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../tree/tree.h"
#include "../arrayList/arrayList.h"

#define TYPE int
#define _OUTPUT_TEST // defined if you want to make a report

typedef TYPE (*COMPARE)(TYPE num1, TYPE num2);

TYPE greater(TYPE num1, TYPE num2){
	return num1 >= num2;
}

TYPE smaller(TYPE num1, TYPE num2){
	return num1 <= num2;
}

void swap(TYPE *num1, TYPE *num2){
	// swap two elements
	// version 1
	TYPE tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
	
	// version 2
	/*
	*num1 = *num1 ^ *num2;
	*num2 = *num1 ^ *num2;
	*num1 = *num1 ^ *num2;
	*/
	
	// version 3
	/*
	*num1 = *num1 ^ *num2 ^ (*num2 = *num1)
	*/
}

void bubbleSort(TYPE* input, int len, COMPARE cmp){
	int i, j, flag = 1;
	TYPE tmp;
	// a modified version of bubble sort, 
	// stopping to compare when there is nothing to swap.
	for(i = 0;i < len && flag == 1;i++){
		flag = 0;
		for(j = 0;j < len - i - 1;j++){
			if(cmp(input[j], input[j + 1])){
				swap(&input[j], &input[j + 1]);
				flag = 1;
			}
		}
	}
}

void insertSort(TYPE* input, int len, COMPARE cmp){
	int i, j;
	TYPE tmp, prev;
	for(i = 1;i < len;i++){
		// find a specified position to insert input[i]
		prev = input[i];
		for(j = 0;j < i;j++)
			if(cmp(input[j], prev))
				break;
		
		// move elements after that position
		for(;j < i;j++){
			tmp = input[j];
			input[j] = prev;
			prev = tmp;
		}
		
		input[i] = prev;
	}
}

void selectSort(TYPE* input, int len, COMPARE cmp){
	int i, j, min_index;
	TYPE tmp, min;
	for(i = 0;i < len - 1;i++){
		min = INT_MAX;
		min_index = -1;
		
		// find maximum or minimum element at the rest of elements
		for(j = i;j < len;j++){
			if(cmp(min, input[j])){
				min = input[j];
				min_index = j;
			}
		}
		swap(&input[min_index], &input[i]);
	}
}

void vQsort(TYPE *input, int start, int end, COMPARE cmp){
	int left, right;
	if(start >= end) return;
	
	left = start; right = end;
	while(1){
		// find a child that are less than left child from right to left
		while(!cmp(input[left], input[right])) right--;
		if(left >= right) break;
		swap(&input[left++], &input[right]);
		
		// find a child that are greater than right child from left to right
		while(!cmp(input[left], input[right])) left++;
		if(left >= right) break;
		swap(&input[left], &input[right--]);
	}
	
	vQsort(input, start, left, cmp);
	vQsort(input, left + 1, end, cmp);
}

void quickSort(TYPE *input, int len, COMPARE cmp){
	vQsort(input, 0, len - 1, cmp);
}

void conquer(TYPE *tOutput, int iStart, int iMiddle, int iEnd, TYPE *tInput, COMPARE cmp){
	int i, j, k;
	i = iStart; j = iMiddle + 1;
	for(k = iStart;k <= iEnd;k++){
		if(i == iMiddle + 1 || j <= iEnd && cmp(tInput[i], tInput[j])){
			tOutput[k] = tInput[j++];
		}else
			tOutput[k] = tInput[i++];
	}
}

void divide(TYPE *output, int left, int right, TYPE *input, COMPARE cmp){
	int middle;
	if(right - left < 1) return;
	
	middle = (left + right) >> 1;
	divide(input, left, middle, output, cmp);
	divide(input, middle + 1, right, output, cmp);
	conquer(output, left, middle, right, input, cmp);
}

void mergeSort(TYPE *input, int len, COMPARE cmp){
	TYPE *output;
	output = (TYPE*) malloc(sizeof(TYPE) * len);
	memcpy(output, input, sizeof(TYPE) * len);
	divide(input, 0, len - 1, output, cmp);
	free(output);
}

void inorderTraversalSort(TreeNode *root, TYPE *input, int *ptr){
	if(root == NULL) return;
	
	// get final sorted list	
	inorderTraversalSort(root->left, input, ptr);
	input[(*ptr)++] = root->val;
	inorderTraversalSort(root->right, input, ptr);
}

void treeSort(TYPE *input, int len, COMPARE cmp){
	int idx;
	TreeNode* root;
	if(len <= 0) return;
	
	// construct tree
	root = initTree(input[0]);
	for(idx = 1;idx < len;idx++)
		tInsert(&root, input[idx]);
	
	// inorder traversal
	idx = 0;
	inorderTraversalSort(root, input, &idx);
}

void heapify(TYPE *input, int len, int idx, COMPARE cmp){
    int l = (idx << 1) + 1, r = (idx << 1) + 2;
    int largest = idx;
    
	// find maximum or minimum among parent and two children
    if(l < len && cmp(input[l], input[idx]))
        largest = l;
    
    if(r < len && cmp(input[r], input[largest]))
        largest = r;
    
    if(largest != idx){
        swap(&input[idx], &input[largest]);
        heapify(input, len, largest, cmp);
    }
}

void printArray(TYPE *input, int len){
	int i;
	for(i = 0;i < len;i++)
		printf("%d ", input[i]);
	printf("\n");
}

void heapSort(TYPE *input, int len, COMPARE cmp){
    int idx;
    // build maximum heap or minimum heap
    for(idx = (len >> 1);idx >= 0;idx--)
        heapify(input, len, idx, cmp);
    
    // heap sort
    for(idx = 0;idx < len;idx++){
        swap(&input[0], &input[len - 1 - idx]);
        heapify(input, len - 1 - idx, 0, cmp);
    }
}

void radixSort(TYPE *input, int len, COMPARE cmp){
	const int RADIX = 10;
    int bucket, elem, idx, radix, order, prev, round, remainder, sorted;
	ArrayList buckets[RADIX];
    
	// initialization
	for(idx = 0;idx < RADIX;idx++)
		buckets[idx] = initAL();
	
	radix = 1; sorted = 0;
	for(round = 0;round < 10 && !sorted;round++){
		// put it into buckets by remainder
		for(elem = 0;elem < len;elem++){
			remainder = (input[elem] / radix) % 10;
			pushAL(&buckets[remainder], input[elem]);
		}
		
		// reorder
		elem = sorted = 0;
		for(bucket = 0;bucket < RADIX;bucket++){
			int size = getALSize(&buckets[bucket]);
			if(size == len) sorted = 1;
			for(order = 0;order < size;order++)
				input[elem++] = getAL(&buckets[bucket], order);
			clearAL(&buckets[bucket]);
		}
		
		radix *= 10;
	}
	
}
