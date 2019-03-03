
#ifndef _HASH_H
#define _HASH_H

#define TYPE_HASH int
#define HASH_ARRAY_SIZE 10
#define Hash_key(v) (v % HASH_ARRAY_SIZE)

#include "../common/debug.h"

typedef struct hashNode HashNode;
struct hashNode{
    TYPE_HASH val;
    HashNode* next;
};

typedef struct hash Hash;
struct hash{
    HashNode** arr;
};

int initHash(Hash* h);
int existHash(Hash* h, TYPE_HASH val);
void addHash(Hash* h, TYPE_HASH val);
void removeHash(Hash* h, TYPE_HASH val);
void clearHash(Hash* h);

#endif // _HASH_H

