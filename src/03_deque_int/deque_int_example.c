#include <stdio.h>
#include <iso646.h>
#include <assert.h>

#include "deque_int.h"

/*
    A simple example that demonstrates how to use our
    doubly linked list (which is a deque, a double-ended queue).

    It can only store integers, it's not generic.
*/

int main()
{
    DequeInt *li = deq_create();

    assert(deq_empty(li));

    for (int i = 1; i <= 5; ++i) {
        deq_append(li, i);
    }
    assert(li->length == 5);

    deq_print(li);

    puts("------------");

    deq_print_reverse(li);

    puts("------------");

    deq_clear(li);
    assert(deq_empty(li));
    assert(li->length == 0);

    for (int i = 1; i <= 5; ++i) {
        deq_append(li, i);
    }

    while (not deq_empty(li))
    {
        int elem = deq_popleft(li);
        printf("popleft: %d\n", elem);
        deq_print(li);
        puts("---");
    }
    assert(deq_empty(li));

    puts("------------");

    for (int i = 1; i <= 5; ++i) {
        deq_append(li, i);
    }

    while (not deq_empty(li))
    {
        int elem = deq_pop(li);
        printf("pop: %d\n", elem);
        deq_print(li);
        puts("---");
    }
    assert(deq_empty(li));

    puts("------------");

    deq_append(li, 42);
    assert(li->length == 1);

    li = deq_destroy(li);
    assert(li == NULL);

    return 0;
}
