#include <stdio.h>
#include <iso646.h>

#include "linkedlist_int.h"

/*
    A simple example that demonstrates how to use our
    singly linked list. It can only store integers,
    it's not generic.
*/

int main()
{
    LinkedListInt *li = ll_create();

    for (int i = 1; i <= 5; ++i) {
        ll_append(li, i);
    }

    ll_print(li);

    ll_clear(li);

    puts("------------");

    for (int i = 10; i <= 15; ++i) {
        ll_append(li, i);
    }

    ll_print(li);

    puts("------------");

    while (not ll_empty(li))
    {
        int elem = ll_popleft(li);
        printf("popleft: %d\n", elem);
        ll_print(li);
        puts("------------");
    }

    ll_append(li, 42);
    ll_print(li);
    printf("number of elements: %d\n", li->length);

    li = ll_destroy(li);

    return 0;
}
