#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *create_array (int n, int init) {
    int *a = malloc(n * sizeof(*a));
    if (a)
        while (n--)
            a[n] = init;
    return a;
}

void die(void) {
    puts("Fuck!");
    exit(1);
}

int main(void) {
    int size, init;

    printf("How bit a fucking array you want? ");
    if (scanf("%d", &size) < 1) die();

    printf("What to init it with? ");
    if (scanf("%d", &init) < 1) die();

    int *a = create_array(size, init);
    if (!a) die();

    printf("Here's your fucking array:");
    for (int i = 0; i < size; i++)
        printf(" %d", a[i]);
    putchar('\n');

    return 1;
}
