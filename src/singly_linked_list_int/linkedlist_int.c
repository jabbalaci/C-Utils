#include "linkedlist_int.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// ##########
// private ##
// ##########

// if mem. allocation fails
void mem_error_exit()
{
    fprintf(stderr, "Error: cannot allocate memory\n");
    exit(1);
}

// free every node
void free_nodes(LinkedListInt *self)
{
    SLL_Node *prev = NULL;
    SLL_Node *curr = self->head;

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
LinkedListInt * ll_create()
{
    LinkedListInt *result = malloc(sizeof(LinkedListInt));
    if (result == NULL) {
        mem_error_exit();
    }

    result->head = NULL;
    result->tail = NULL;
    result->length = 0;

    return result;
}

// clear the object, i.e. remove all its elements (reinitialize the object)
void ll_clear(LinkedListInt *self)
{
    free_nodes(self);

    self->head = NULL;
    self->tail = NULL;
    self->length = 0;
}

bool ll_empty(LinkedListInt *self)
{
    return (self->head == NULL);
}

// add a new element to the end of the linked list
void ll_append(LinkedListInt *self, int data)
{
    SLL_Node *new = malloc(sizeof(SLL_Node));
    if (new == NULL) {
        mem_error_exit();
    }
    new->data = data;
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

// remove the first node and return its data
int ll_popleft(LinkedListInt *self)
{
    assert(self->head != NULL);
    //
    int result = self->head->data;
    SLL_Node *first = self->head;
    self->head = self->head->next;

    if (self->head == NULL) {
        self->tail = NULL;
    }
    free(first);
    self->length -= 1;

    return result;
}

// print the elements (for debugging purposes)
void ll_print(LinkedListInt *self)
{
    SLL_Node *curr = self->head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    puts("");
}

// destroy the object and free the allocated mem. areas
void * ll_destroy(LinkedListInt *self)
{
    ll_clear(self);
    free(self);
    //
    return NULL;
}
