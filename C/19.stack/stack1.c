#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define PUBLIC /* empty */
#define PRIVATE static
#define STACK_SIZE 100

PRIVATE int contents[STACK_SIZE];
PRIVATE int top = 0;

PRIVATE void die(const char *message) {
    puts(message);
    exit(EXIT_FAILURE);
}

PUBLIC void make_empty(void) { top = 0; }
PUBLIC bool is_empty(void) { return top == 0; }
PUBLIC bool is_full(void) { return top == STACK_SIZE; }
PUBLIC void push(int i) {
    if (is_full()) die("Stack is full. Fuck off!");
    contents[top++] = i;
}
PUBLIC int pop(void) {
    if (is_empty()) die("Stack is empty. Fuck off!");
    return contents[--top];
}
