#include "stackADT.h"
#include <stdio.h>
#include <stdlib.h>

#define PUBLIC /* empty */
#define PRIVATE static
#define STACK_SIZE 100

struct stack_type {
    int contents[STACK_SIZE];
    int top;
};
PRIVATE void die(const char *message) {
    puts(message);
    exit(EXIT_FAILURE);
}

PUBLIC char *impl(void) { return "Array-based Multi-Stacker v0.001001"; }
PUBLIC Stack create(void) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL) die("Could not create a fucking Stack. Fuck off");
    s->top = 0;
    return s;
}
PUBLIC void destroy(Stack s) { free(s); }
PUBLIC void make_empty(Stack s) { s->top = 0; }
PUBLIC bool is_empty(Stack s) { return s->top == 0; }
PUBLIC bool is_full(Stack s) { return s->top == STACK_SIZE; }
PUBLIC void push(Stack s, int i) {
    if (is_full(s)) die("Stack is full. Fuck off!");
    s->contents[s->top++] = i;
}
PUBLIC int pop(Stack s) {
    if (is_empty(s)) die("Stack is empty. Fuck off!");
    return s->contents[--s->top];
}
