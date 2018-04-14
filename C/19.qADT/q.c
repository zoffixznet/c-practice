#include "q.h"
#include <stdlib.h>
#include <stdio.h>

static void die(const char *s) {
    printf("FUCKING ERROR: %s", s);
    exit(1);
}
static void *q_malloc(size_t size) {
    void *p = malloc(size);
    if (! p)
        die("Could not allocate fucking memory");
    return p;
}

typedef struct node {
    Item item;
    struct node *next;
} *Node;

struct q_type {
    Node first;
};

Q q_create(void) {
    Q q = q_malloc(sizeof(struct q_type));
    q->first = NULL;
    return q;
}
bool q_destroy(Q q) {
    if (! q_is_empty(q)) {
        Node node = q->first, next;
        while ((next = node->next)) {
            next = node->next;
            free(node);
        }
        free(node);
    }
    free(q);
    return true;
}
bool q_insert_item(Q q, Item it) {
    Node node = q_malloc(sizeof(struct node));
    node->next = NULL;
    node->item = it;

    if (q_is_empty(q)) {
        printf("fuck\n");
        q->first = node;
        return true;
    }
    else {
        printf("how the fuck is it full?\n");
        Node head = q->first;
        while (head->next)
            head = head->next;
        head->next = node;
        return true;
    }
}
Item q_pop_item(Q q) {
    if (q_is_empty(q))
        die("The Q is fucking empty. Nothing to pop");
    Node popped = q->first;
    q->first = popped->next;
    Item it = popped->item;
    free(popped);
    return it;
}
Item q_first_item(Q q) {
    if (q_is_empty(q))
        die("The Q is fucking empty. No first item");
    return q->first->item;
}
Item q_last_item(Q q) {
    if (q_is_empty(q))
        die("The Q is fucking empty. No last item");
    Node last = q->first;
    while (last->next)
        last = last->next;
    return last->item;
}
bool q_is_empty(Q q) {
    return q->first ? false : true;
}
