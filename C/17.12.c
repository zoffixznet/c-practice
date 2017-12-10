#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node *last_node(Node *list, int n);
void add(Node **list, int n);

int main(void) {
    Node *list;

    printf("Enter some fucking integers; zero to stop: ");
    while (1) {
        int v;
        if (scanf("%d", &v) < 1 || v == 0) break;
        add(&list, v);
    }

    printf("What value to find the last node for? ");
    int last;
    if (scanf("%d", &last) < 1) exit(1);

    list = last_node(list, last);
    if (! list) {
        puts("No such fucking value, fuck off");
        exit(1);
    }

    printf("Here are the remaining values:");
    list = list->next;
    while (list) {
        printf(" %d", list->value);
        list = list->next;
    }
    putchar('\n');

    return 0;
}

void add(Node **list, int n) {
    Node *node = malloc(sizeof(*node));
    if (! node) {
        puts("Fuck! No more RAM\n");
        exit(1);
    }

    node->value = n;
    node->next  = *list;
    *list = node;
}

Node *last_node(Node *list, int n) {
    Node *seen = NULL;
    while (list) {
        if (list->value == n) seen = list;
        list = list->next;
    }

    return seen;
}
