
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "set.h"

Set* initSet(){
	Set *set = (Set*) malloc(sizeof(Set));
	assert(set != NULL);
	set->t = NULL;
	return set;
}

void addSet(Set *s, TREE_TYPE val){
    assert(s != NULL);
	if(s->t != NULL && !isExistTree(s->t, val)){
		tInsert(&s->t, val);
	}else if(s->t == NULL){
		s->t = initTree(val);
	}
}

void removeSet(Set *s, TREE_TYPE val){
    assert(s != NULL && s->t != NULL);
    tDeletion(&s->t, val);
}

int isExistSet(Set *s, TREE_TYPE val){
	return isExistTree(s->t, val);
}

void releaseSet(Set *s){
	releaseTree(s->t);
}

