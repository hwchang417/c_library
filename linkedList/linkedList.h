
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#define LINKED_LIST_TYPE int

typedef struct node Node;
struct node{
    Node* prev, *next;
    LINKED_LIST_TYPE val;
};

typedef struct linkedList LinkedList;
struct linkedList{
    Node* head, *tail;
};

void init(LinkedList* list);
void push_back(LinkedList* list, int val);
int empty(LinkedList* list);
LINKED_LIST_TYPE pop_back(LinkedList* list);
LINKED_LIST_TYPE pop_front(LinkedList* list);
void push_front(LinkedList* list, int val);
LINKED_LIST_TYPE element(LinkedList* list, int index);

#endif // _LINKEDLIST_H


