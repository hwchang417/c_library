
#include <stdlib.h>
#include "hash.h"

int initHash(Hash* h){
    int index;
    
    h->arr = (HashNode**) calloc(HASH_ARRAY_SIZE, sizeof(TYPE_HASH));
    if(h->arr == NULL){
        DEBUG("Hash, init: no enough memory to allocate\n");
        return FAILURE;
    }
    
    for(index = 0;index < HASH_ARRAY_SIZE;index++)
        h->arr[index] = NULL;
        
    return SUCCESS;
}

int existHash(Hash* h, TYPE_HASH val){
    int index, key;
    HashNode* hn;
    
    //check pointer
    if(h == NULL){
        DEBUG("Hash, exist: NULL pointer to add\n");
        return FAILURE;
    }
    
    //hash list is NULL
    key = Hash_key(val);
    if(!h->arr[key])
        return FAILURE;
        
    //linear probing
    hn = h->arr[key];
    while(hn != NULL && hn->val < val) hn = hn->next;
    
    return hn == NULL ? FAILURE : hn->val == val;
}

void addHash(Hash* h, TYPE_HASH val){
    int index, key;
    HashNode* hn, *newhn, *prev;
    
    //check pointer
    if(h == NULL){
        DEBUG("Hash, add: NULL pointer to add\n");
        return;
    }
    
    //new a hash node
    newhn = (HashNode*) calloc(1, sizeof(HashNode));
    if(!newhn){
        DEBUG("Hash, add: no enough memory to allocate\n");
        return;
    }
    
    //make a hash node
    newhn->next = NULL;
    newhn->val = val;
    
    key = Hash_key(val);
    if(!h->arr[key])
        h->arr[key] = newhn;
    else{
        prev = hn = h->arr[key];
        while(hn != NULL && hn->val < val){
            prev = hn;
            hn = hn->next;
        }
        
        //last node
        if(hn == NULL)
            prev->next = newhn;
        else{
        //last second node
            newhn->next = hn;
            prev->next = newhn;
        }
    }
}

void removeHash(Hash* h, TYPE_HASH val){
    int index, key;
    HashNode* hn, *prev;
    
    if(h == NULL){
        DEBUG("Hash, remove: NULL pointer to remove\n");
        return;
    }
    
    //val does not exist in hash list, return directly
    key = Hash_key(val);
    if(!h->arr[key])
        return FAILURE;
    
    //linear probing
    prev = hn = h->arr[key];
    while(hn != NULL && hn->val < val){
        prev = hn;
        hn = hn->next;
    }
    
    //not exist
    if(hn == NULL)
        return;
    else if(prev == h->arr[key]){
        h->arr[key] = prev->next;
        free(prev);
    }else{
        prev->next = hn->next;
        free(hn);
    }
}

void clearHash(Hash* h){
    int index;
    HashNode* hn, *tmp;
    
    for(index = 0;index < HASH_ARRAY_SIZE;index++){
        //free nodes in hash list
        hn = h->arr[index];
        while(hn != NULL){
            tmp = hn;
            hn = hn->next;
            free(tmp);
        }
        h->arr[index] = NULL;
    }
}

