#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

int count_occurences(Node *list, int n);
void add(Node **list, int n);

int main(void) {
    Node *list;

    printf("Enter some fucking integers; zero to stop: ");
    while (1) {
        int v;
        if (scanf("%d", &v) < 1 || v == 0) break;
        add(&list, v);
    }

    printf("What fucking value to count? ");
    int wanted;
    if (scanf("%d", &wanted) < 1) exit(1);
    printf("%d appears %d times in your fucking numbers\n", wanted,
        count_occurences(list, wanted));

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

int count_occurences(Node *list, int n) {
    int count = 0;
    while (list) {
        if (list->value == n) count++;
        list = list->next;
    }

    return count;
}
