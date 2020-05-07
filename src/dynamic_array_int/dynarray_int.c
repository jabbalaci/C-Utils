#include "dynarray_int.h"

#include <stdio.h>
#include <stdlib.h>

// ##########
// private ##
// ##########

// if mem. allocation fails
void mem_error_exit(void)
{
    fprintf(stderr, "Error: cannot allocate memory\n");
    exit(1);
}

// compare two integers
int da_cmp(const void *left, const void *right)
{
    const int *a = left;
    const int *b = right;

    return *a - *b;
}

// #########
// public ##
// #########

// create a new dynamic array object
DynArrayInt * da_create(void)
{
    DynArrayInt *result = malloc(sizeof(DynArrayInt));
    if (result == NULL) {
        mem_error_exit();
    }

    result->elems = malloc(DA_INITIAL_CAPACITY * sizeof(int));
    if (result->elems == NULL) {
        mem_error_exit();
    }
    result->length = 0;
    result->capacity = DA_INITIAL_CAPACITY;

    return result;
}

// clear the object, i.e. remove all its elements (reinitialize the object)
void da_clear(DynArrayInt *self)
{
    self->elems = realloc(self->elems, DA_INITIAL_CAPACITY * sizeof(int));
    self->length = 0;
    self->capacity = DA_INITIAL_CAPACITY;
}

// add a new element to the dynamic array
void da_append(DynArrayInt *self, int data)
{
    if (self->length == self->capacity)
    {
        int new_capacity = (int)(DA_MULTIPLIER * self->capacity);
        self->elems = realloc(self->elems, new_capacity * sizeof(int));
        if (self->elems == NULL) {
            mem_error_exit();
        }
        self->capacity = new_capacity;
    }
    //
    self->elems[self->length] = data;
    self->length += 1;
}

// print the elements of the dynamic array (for debugging purposes)
void da_print(const DynArrayInt *self)
{
    for (int i = 0; i < self->length; ++i) {
        printf("%d ", self->elems[i]);
    }
    puts("");
}

// sort in place
void da_sort(DynArrayInt *self)
{
    qsort(self->elems, self->length, sizeof(int), da_cmp);
}

// destroy the object and free the allocated mem. areas
void * da_destroy(DynArrayInt *self)
{
    free(self->elems);
    free(self);
    //
    return NULL;
}
