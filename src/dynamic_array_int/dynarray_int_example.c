#include <stdio.h>

#include "dynarray_int.h"

/*
    A simple example that demonstrates how to use our
    dynamic array. DynArrayInt can only store integers,
    it's not generic.
*/

int main()
{
    DynArrayInt *li = da_create();

    for (int i = 1; i <= 5; ++i) {
        da_append(li, i);
    }

    da_print(li);

    da_clear(li);

    puts("------------");

    for (int i = 10; i <= 15; ++i) {
        da_append(li, i);
    }

    da_print(li);

    li = da_destroy(li);

    return 0;
}
