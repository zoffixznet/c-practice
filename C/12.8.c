#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void store_zeros(int *a, int n);

int main(void) {
    int a[N];

    srand((unsigned) time(NULL));
    printf("The fucking array is:    ");
    for (int *p = a; p - a < N; p++)
        printf(" %d", *p = rand() % 10);
    putchar('\n');

    printf("Storing fucking zeros in the array...\n");
    store_zeros(a, N);

    printf("The fucking array now is:");
    for (int *p = a; p - a < N; p++)
        printf(" %d", *p);
    putchar('\n');

    return 0;
}

void store_zeros(int *a, int n) {
    for (int *p = a; p - a < n; p++)
        *p = 0;
}
