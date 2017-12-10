#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int sorter(const void *a, const void *b) {
    return *(int *)a < *(int *)b
        ? -1 : *(int *)a == *(int *)b
            ? 0 : 1;
}

int main(void) {
    int a[SIZE] = { 1, 3, 2, 5, 8, 4, 9, 0, 6, 7 };

    qsort(&a[SIZE/2], SIZE/2, sizeof(a[0]), sorter);

    printf("Sorted array:");
    for (int i = 0; i < SIZE; i++)
        printf(" %d", a[i]);
    putchar('\n');

    return 0;
}
