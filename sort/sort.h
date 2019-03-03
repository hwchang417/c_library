
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../tree/tree.h"

#define TYPE int
#define _OUTPUT_TEST // defined if you want to make a report

#ifndef _SORT_H
#define _SORT_H

int greater(int num1, int num2);
void bubble_sort(int* input, int len, int (*cmp)(int num1, int num2));

typedef TYPE (*COMPARE)(TYPE num1, TYPE num2);

TYPE greater(TYPE num1, TYPE num2);
TYPE smaller(TYPE num1, TYPE num2);
void swap(TYPE *num1, TYPE *num2);
void bubbleSort(TYPE* input, int len, COMPARE cmp);
void insertSort(TYPE* input, int len, COMPARE cmp);
void selectSort(TYPE* input, int len, COMPARE cmp);
void quickSort(TYPE *input, int len, COMPARE cmp);
void mergeSort(TYPE *input, int len, COMPARE cmp);
void treeSort(TYPE *input, int len, COMPARE cmp);
void printArray(TYPE *input, int len);
void heapSort(TYPE *input, int len, COMPARE cmp);
void radixSort(TYPE *input, int len, COMPARE cmp);

#endif
