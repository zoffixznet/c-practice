#include "stack.h"
#include <stdio.h>

int main(void) {
    puts("Pushing");
    for (int i = 0; i < 10; i++)
        push(i);
    printf("is full? %d\n", is_full());
    puts("Popping");
    while (! is_empty())
        // printf("\tPopped value is: %d\n", pop());
    printf("is full? %d\n", is_full());
    puts("ZOMFG! HEXPLOSION!");
    pop();
    return 1;
}
