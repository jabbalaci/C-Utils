#pragma once

#include <stdbool.h>

// singly linked list node
typedef struct _sll_node {
    int data;
    struct _sll_node *next;
} SLL_Node;

// singly linked list
typedef struct {
    SLL_Node *head;
    SLL_Node *tail;
    int length;    // number of inserted elements
} LinkedListInt;

LinkedListInt * ll_create(void);
void ll_clear(LinkedListInt *self);
bool ll_empty(const LinkedListInt *self);
void ll_append(LinkedListInt *self, int data);
int ll_popleft(LinkedListInt *self);
void ll_print(const LinkedListInt *self);
void * ll_destroy(LinkedListInt *self);
