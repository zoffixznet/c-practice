#include "stackADT.h"
#include <stdio.h>

int main(void) {
    Stack s1 = create(), s2 = create();

    puts(impl());
    puts("Pushing s1");
    for (int i = 0; i < 10; i++)
        push(s1, i);
    puts("Pushing s2");
    for (int i = 0; i < 5; i++)
        push(s2, i);

    printf("s1 is full? %d\n", is_full(s1));
    printf("s2 is full? %d\n", is_full(s2));
    puts("Popping s1");
    while (! is_empty(s1))
        printf("\tPopped value is: %d\n", pop(s1));
    puts("Popping s2");
    while (! is_empty(s2))
        printf("\tPopped value is: %d\n", pop(s2));
    printf("s1 is full? %d\n", is_full(s1));
    printf("s2 is full? %d\n", is_full(s2));

    puts("ZOMFG! HEXPLOSION!");
    pop(s1);

    destroy(s1);
    destroy(s2);
    return 1;
}
