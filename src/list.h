#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME
#include <stdio.h>
#include <stdbool.h>

typedef struct _node
{
    struct _node* prev;
    struct _node* next;
    int key;
} Node;

typedef struct list
{
    Node* head;
    Node* tail;
    int count;
} List;

Node* node_new(int key);
List* list_new();

void list_insert(Node* node, int value);
void list_push_back(List* myList, int value);
void list_push_front(List* myList, int value);

Node* list_find(List* myList, int value);

void list_pop_back(List* myList);
void list_pop_front(List* myList);
void list_remove(List* myList, int value);


void list_traverse(List* myList);
void list_reverse(List* myList);

void list_destroy(List* myList);

#endif