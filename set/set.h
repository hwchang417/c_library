
#ifndef _SET_H
#define _SET_H

#include "../tree/tree.h"

typedef struct set{
	TreeNode *t;
}Set;

Set* initSet();
void addSet(Set *s, TREE_TYPE val);
void removeSet(Set *s, TREE_TYPE val);
int isExistSet(Set *s, TREE_TYPE val);
void releaseSet(Set *s);

#endif
