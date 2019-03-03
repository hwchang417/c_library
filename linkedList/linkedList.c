
#include "linkedList.h"
#include "../common/debug.h"

void init(LinkedList* list){
    list->head = list->tail = NULL;
}

void push_back(LinkedList* list, int val){
    if(empty(list)){
        list->tail = list->head = (Node*) calloc(1, sizeof(Node));
        if(list->head == NULL){
            DEBUG("no enough memory to allocate\n");
            return;
        }
        list->head->val = val;
        list->head->prev = NULL;
        list->head->next = NULL;
    }else{
        list->tail->next = (Node*) calloc(1, sizeof(Node));
        if(list->tail->next == NULL){
            DEBUG("no enough memory to allocate\n");
            return;
        }
        list->tail->next->prev = list->tail;
        list->tail = list->tail->next;
        list->tail->val = val;
        list->tail->next = NULL;
    }
}

int empty(LinkedList* list){
    return (list == NULL || list->head == NULL);
}

LINKED_LIST_TYPE pop_back(LinkedList* list){
    int ret;
    Node* tmp;
    if(list == NULL || list->tail == NULL)
        return FAILURE;
    tmp = list->tail;
    ret = tmp->val;
    list->tail = list->tail->prev;
    if(list->tail != NULL)
        list->tail->next = NULL;
    free(tmp);
    return ret;
}

LINKED_LIST_TYPE pop_front(LinkedList* list){
    int ret;
    Node* tmp;
    if(list == NULL || list->head == NULL)
        return FAILURE;
    tmp = list->head;
    ret = tmp->val;
    list->head = list->head->next;
    if(list->head != NULL)
        list->head->prev = NULL;
    free(tmp);
    return ret;
}

void push_front(LinkedList* list, int val){

    if(list == NULL){
        DEBUG("list is null\n");
        return;
    }

    if(list->head == NULL){
        list->tail = list->head = (Node*) calloc(1, sizeof(Node));
        if(list->head == NULL){
            DEBUG("no enough memory to allocate\n");
            return;
        }
        list->head->val = val;
        list->head->prev = NULL;
        list->head->next = NULL;
    }else{
        list->head->prev = (Node*) calloc(1, sizeof(Node));
        if(list->head->prev == NULL){
            DEBUG("no enough memory to allocate\n");
            return;
        }
        list->head->prev->next = list->head;
        list->head = list->head->prev;
        list->head->val = val;
        list->head->prev = NULL;
    }
    DEBUG("push_front = %d\n", list->head->val);
}

LINKED_LIST_TYPE element(LinkedList* list, int index){
    int i = 0;
    Node* tmp;
    if(list == NULL) return FAILURE;

    tmp = list->head;
    while(tmp != NULL && i != index){
        tmp = tmp->next;
        i++;
    }

    return tmp != NULL ? tmp->val : FAILURE;
}
