#include "q.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ITEM_SIZE 1000
char buffer[MAX_ITEM_SIZE+1];
Item read_item(char a[], int n);

int main(void) {
    Q q = q_create();
    int command;
    while(1) {
        printf("\ni ITEM - insert item into queue\n"
                 "p - pop an item off the queue\n"
                 "f - show first item in the queue\n"
                 "l - show last item in the queue\n"
                 "e - show whether queue is empty\n"
                 "q - quit\n"
               "\nEnter a fucking command: ");
        while (isspace(command = getchar()))
            ;
        switch (command) {
            case 'i':
                q_insert_item(q, read_item(buffer, MAX_ITEM_SIZE));
                break;
            case 'p':
                printf("Popped item: %s\n", q_pop_item(q)); break;
            case 'f':
                printf("First item: %s\n", q_first_item(q)); break;
            case 'l':
                printf("Last item: %s\n", q_last_item(q)); break;
            case 'e':
                puts(q_is_empty(q) ? "Empty" : "Not Empty"); break;
            case 'q':
                puts("Buh-bye"); q_destroy(q); exit(0); break;
            default:
                printf("Wrong fucking command, you moron!");
        }
    }
}

Item read_item(char a[], int n) {
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;
    while (ch != '\n' && ch != EOF) {
        if (i < n)
            a[i++] = ch;
        ch = getchar();
    }
    a[i] = '\0';
    return a;
}
