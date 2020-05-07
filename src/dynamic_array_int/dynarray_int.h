#pragma once

#define DA_INITIAL_CAPACITY 10
#define DA_MULTIPLIER 1.5

// a dynamic array for storing integers
typedef struct {
    int *elems;    // points on the allocated area
    int length;    // number of inserted elements
    int capacity;  // physical capacity of the allocated area
                   // capacity must be >= length
} DynArrayInt;

DynArrayInt * da_create();
void da_clear(DynArrayInt *self);
void da_append(DynArrayInt *self, int data);
void da_print(DynArrayInt *self);
void * da_destroy(DynArrayInt *self);
