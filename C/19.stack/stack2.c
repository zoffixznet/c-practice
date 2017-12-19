#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define PUBLIC /* empty */
#define PRIVATE static

typedef struct node {
    int value;
    struct node *next;
} Node;
PRIVATE Node *stack = NULL;

PRIVATE void die(const char *message) {
    puts(message);
    exit(EXIT_FAILURE);
}

PUBLIC char *impl(void) { return "Linked-list-based Stacker v0.001001"; }

PUBLIC void make_empty(void) {
    while (stack) {
        Node *del_node = stack;
        stack = stack->next;
        free(del_node);
    }
}
PUBLIC bool is_empty(void) { return stack == NULL; }
PUBLIC bool is_full(void) { return false; }
PUBLIC void push(int i) {
    Node *new_node = malloc(sizeof(*new_node));
    if (! new_node) die("Could not allocate memory. Fuck off!");
    new_node->value = i;
    new_node->next = stack;
    stack = new_node;
}
PUBLIC int pop(void) {
    if (is_empty()) die("Stack is empty. Fuck off!");

    int ret = stack->value;
    Node *del_node = stack;
    stack = stack->next;
    free(del_node);
    return ret;
}
