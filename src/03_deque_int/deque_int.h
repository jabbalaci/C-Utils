#pragma once

#include <stdbool.h>

// doubly linked list node
typedef struct _dll_node {
    int data;
    struct _dll_node *prev;
    struct _dll_node *next;
} DLL_Node;

// doubly linked list, deque
typedef struct {
    DLL_Node *head;
    DLL_Node *tail;
    int length;    // number of inserted elements
} DequeInt;

DequeInt * deq_create(void);
void deq_clear(DequeInt *self);
bool deq_empty(const DequeInt *self);
void deq_append(DequeInt *self, int data);
void deq_appendleft(DequeInt *self, int data);
int deq_pop(DequeInt *self);
int deq_popleft(DequeInt *self);
void deq_print(const DequeInt *self);
void deq_print_reverse(const DequeInt *self);
void * deq_destroy(DequeInt *self);
