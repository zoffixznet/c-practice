#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    long long value;
    struct node *next;
} Node;

void add_to_list(Node **list, long long value) {
    Node *node;
    if (!(node = malloc(sizeof(Node)))) {
        puts("Failed to allocate fucking memory");
        exit(1);
    }

    node->value = value;
    node->next  = *list;
    *list = node;
}

Node *read_numbers(void) {
    Node *first = NULL;
    long long n;

    printf("Enter some fucking integers or zero to stop: ");
    while (1) {
        if (scanf("%lld", &n) <= 0 || n == 0) break;
        add_to_list(&first, n);
    }
    return first;
}

void print_numbers(Node *list, const char *s) {
    printf("%s", s ? s : "You've entered these fucking numbers:");
    while (list) {
        printf(" %lld", list->value);
        list = list->next;
    }
    putchar('\n');
}

Node *search_list(Node *list, long long n) {
    while (list && list->value != n)
        list = list->next;
    return list;
}

// bool delete_from_list(Node **list, long long n) {
//     Node *prev = NULL, *cur = *list;
//     for (
//         ; cur != NULL && cur->value != n
//         ; prev = cur, cur = cur->next
//     );
//
//     if (cur) { // we found shit to delete
//         if (prev) // we're in the middle/end of the list
//             prev->next = cur->next;
//         else // we're right at the start of the fucking list
//             *list = cur->next;
//         free(cur);
//         return delete_from_list(list, n);
//     }
//     else
//         return false;
// }

// Node *delete_from_list(Node *list, long long n) {
//     Node *prev, *cur;
//     for (
//           cur = list, prev = NULL
//         ; cur != NULL && cur->value != n
//         ; prev = cur, cur = cur->next
//     );
//
//     if (!cur) return list;
//     if (!prev) list = list->next;
//     else prev->next = cur->next;
//     free(cur);
//
//     return list;
// }

Node *delete_from_list(Node *list, long long n) {
    if (! list) return list;

    Node *p = list;
    if (p->value == n) { // wanted value is the first item
        list = p->next;
        free(p);
        return list;
    }

    // seek to end or to the value we want deleted
    while (p->next && p->next->value != n)
        p = p->next;

    if (p->next) { // we found shit to delete; it's in p->next->value
        // since we can't use another variable, don't see a way to relink
        // over shit to delete AND free() the shit, so we'll shift all the
        // values, effectivelly ending up with shit to free() at the end, with
        // no need to relink anything
        while (p->next->next) {
            p->next->value = p->next->next->value;
            p = p->next;
        }
        free(p->next);
        p->next = NULL;
    }

    return list;
}

void clean_up(Node **list) {
    Node *cur;
    while ((cur = *list)) {
        *list = (*list)->next;
        free(cur);
    }
}

int main(void) {
    Node *nums = read_numbers();
    print_numbers(nums, NULL);

    long long wanted = 42;
    Node *found = search_list(nums, wanted);

    if (found) {
        printf("%lld was fucking found! ", wanted);
        print_numbers(found->next, "These numbers follow it:");
    }
    else
        printf("%lld is not in the fucking list\n", wanted);

    nums = delete_from_list(nums, 72);
    print_numbers(nums, "After deletion:");

    clean_up(&nums);
    return 1;
}
