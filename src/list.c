#include "list.h"
#include <stdlib.h>

List* list_new()
{
    List* myList = malloc(sizeof(List));
    myList->head = NULL;
    myList->tail = NULL;
    myList->count = 0;

    return myList;
}
Node* node_new(int key) {
    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    return newNode;
}

void list_push_front(List* myList, int value) 
{
    Node* newNode = node_new(value);

    newNode->next = myList->head;
    newNode->prev = NULL;
    
    if (myList->head) 
        myList->head->prev = newNode;
    else
        myList->tail = newNode;
            
    myList->head = newNode;
    myList->count++;
}

void list_push_back(List* myList, int value) 
{
    Node* newNode = node_new(value);

    newNode->prev = myList->tail;
    newNode->next = NULL;
        
    if (myList->tail) 
        myList->tail->next = newNode;        
    else
        myList->head = newNode;
    
    myList->tail = newNode;
    myList->count++;
    
}

Node* list_find(List* myList, int value)
{
    Node* tempNode = myList->head;
    
    while (tempNode != NULL && tempNode->key != value)
        tempNode = tempNode->next ;
    
    return tempNode;
}

void list_insert(Node* node, int value) {
    Node* newNode = node_new(value);
    newNode->next = node->next;
    newNode->prev = node;
    
    if (node->next)
        node->next->prev = newNode;

    node->next = newNode;
}

void list_pop_back(List* myList) 
{
    Node* tempNode = myList->tail;
    if (!myList->count) return;

    if (tempNode->prev) 
        tempNode->prev->next=NULL;   
    else 
        myList->head = NULL;

    myList->tail = tempNode->prev;
    myList->count--;

    free(tempNode);
}

void list_pop_front(List* myList)
{
    Node* tempNode = myList->head;
    if (!myList->count) return;

    if (tempNode->next) 
        tempNode->next->prev=NULL;
    else
        myList->tail = NULL;

    myList->head = tempNode->next;
    myList->count--;

    free(tempNode);
}

void list_remove(List* myList, int value)
{
    Node* tempNode = list_find(myList, value);
    if (!tempNode) return;

    if (!tempNode->next) 
        list_pop_back(myList);
    else if (!tempNode->prev) 
        list_pop_front(myList);
    else 
    {
        tempNode->next->prev = tempNode->prev;
        tempNode->prev->next = tempNode->next;
        myList->count--;
        free(tempNode);
    }
}

void list_traverse(List* myList) 
{
    Node* tempNode = myList->head;

    printf("List traverse (n=%d): ", myList->count);

    printf("->");
    while (tempNode != NULL) {
        printf("%d->", tempNode->key);
        tempNode = tempNode->next;
    }
    printf("\n");
}

void list_reverse(List* myList) 
{
    Node* tempNode = myList->tail;

    printf("List reverse (n=%d): ", myList->count);

    while (tempNode != NULL) {
        printf("<-%d", tempNode->key);
        tempNode = tempNode->prev;
    }
    printf("<-");
    printf("\n");
}

