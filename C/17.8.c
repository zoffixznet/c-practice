#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

void empty(Node **stack);
bool push(Node **stack, int i);
int pop(Node **stack);

int main(void) {
    Node *stack = NULL;

    printf("Enter some fucking integers; zero to stop: ");
    while(1) {
        int v;
        if (scanf("%d", &v) < 1 || v == 0) break;
        push(&stack, v);
    }

    printf("\nYou've entered these fucking numbers:");
    while (stack)
        printf(" %d", pop(&stack));
    putchar('\n');

    return 1;
}

void empty(Node **stack) {
    if (*stack) {
        while ((*stack)->next) {
            Node *node = *stack;
            *stack = (*stack)->next;
            free(node);
        }
        free(*stack);
        *stack = NULL;
    }
}

bool push(Node **stack, int i) {
    Node *node = malloc(sizeof(*node));
    if (! node) {
        printf("Fuck! Ain't no more fucking memory, bruh\n");
        return false;
    }

    node->value = i;
    node->next  = *stack;
    *stack = node;

    return true;
}
int pop(Node **stack) {
    if (! *stack) {
        printf("Fuck! Stack underfuckingflow\n");
        exit(1);
    }

    int v = (*stack)->value;
    if ((*stack)->next) {
        Node *node = *stack;
        *stack = (*stack)->next;
        free(node);
    }
    else {
        free(*stack);
        *stack = NULL;
    }
    return v;
}
