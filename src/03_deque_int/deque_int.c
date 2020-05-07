#include "deque_int.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// ##########
// private ##
// ##########

// if mem. allocation fails
void mem_error_exit(void)
{
    fprintf(stderr, "Error: cannot allocate memory\n");
    exit(1);
}

// free every node
void free_nodes(DequeInt *self)
{
    DLL_Node *prev = NULL;
    DLL_Node *curr = self->head;

    while (curr != NULL)
    {
        free(prev);
        prev = curr;
        curr = curr->next;
    }
    free(prev);
}

// #########
// public ##
// #########

// create an empty singly linked list object
DequeInt * deq_create(void)
{
    DequeInt *result = malloc(sizeof(DequeInt));
    if (result == NULL) {
        mem_error_exit();
    }

    result->head = NULL;
    result->tail = NULL;
    result->length = 0;

    return result;
}

// clear the object, i.e. remove all its elements (reinitialize the object)
void deq_clear(DequeInt *self)
{
    free_nodes(self);

    self->head = NULL;
    self->tail = NULL;
    self->length = 0;
}

bool deq_empty(const DequeInt *self)
{
    return (self->head == NULL);
}

// ADD the element to the RIGHT side of the deque
void deq_append(DequeInt *self, int data)
{
    DLL_Node *new = malloc(sizeof(DLL_Node));
    if (new == NULL) {
        mem_error_exit();
    }
    new->data = data;
    new->prev = self->tail;
    new->next = NULL;

    if (self->head == NULL)
    {
        self->head = new;
        self->tail = new;
    }
    else
    {
        self->tail->next = new;
        self->tail = new;
    }

    self->length += 1;
}

// ADD the element to the LEFT side of the deque
void deq_appendleft(DequeInt *self, int data)
{
    DLL_Node *new = malloc(sizeof(DLL_Node));
    if (new == NULL) {
        mem_error_exit();
    }
    new->data = data;
    new->prev = NULL;
    new->next = self->head;

    if (self->head == NULL)
    {
        self->head = new;
        self->tail = new;
    }
    else
    {
        self->head->prev = new;
        self->head = new;
    }

    self->length += 1;
}

// Remove and return an element from the RIGHT side of the deque.
// If no elements are present, raises an assert error.
int deq_pop(DequeInt *self)
{
    assert(self->tail != NULL);
    //
    int result = self->tail->data;
    DLL_Node *last = self->tail;
    self->tail = self->tail->prev;

    if (self->tail == NULL) {
        self->head = NULL;
    }
    else
    {
        self->tail->next = NULL;
    }
    free(last);
    self->length -= 1;

    return result;
}

// Remove and return an element from the LEFT side of the deque.
// If no elements are present, raises an assert error.
int deq_popleft(DequeInt *self)
{
    assert(self->head != NULL);
    //
    int result = self->head->data;
    DLL_Node *first = self->head;
    self->head = self->head->next;

    if (self->head == NULL) {
        self->tail = NULL;
    }
    else
    {
        self->head->prev = NULL;
    }
    free(first);
    self->length -= 1;

    return result;
}

// print the elements from left to right (for debugging purposes)
void deq_print(const DequeInt *self)
{
    DLL_Node *curr = self->head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    puts("");
}

// print the elements from right to left (for debugging purposes)
void deq_print_reverse(const DequeInt *self)
{
    DLL_Node *curr = self->tail;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    puts("");
}

// destroy the object and free the allocated mem. areas
void * deq_destroy(DequeInt *self)
{
    deq_clear(self);
    free(self);
    //
    return NULL;
}
