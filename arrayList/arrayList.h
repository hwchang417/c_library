
#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#define DEFAULT_ARRAYLIST_SIZE 100

typedef struct arrayList{
	int *data, size, curr;
}ArrayList;

ArrayList initAL();
void expandAL(ArrayList *al);
int getAL(ArrayList *al, int index);
int getALSize(ArrayList *al);
void pushAL(ArrayList *al, int val);
void printAL(ArrayList *al);
void clearAL(ArrayList *al);
void releaseAL(ArrayList *al);


#endif
