#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10

bool search(const int a[], int n, int key);

int main(void) {
    int a[N], el;

    srand((unsigned) time(NULL));
    printf("The array is:");
    for (int *p = a; p - a < N; p++)
        printf(" %d", *p = rand() % 10);

    printf("\nLooking for element %d...", el = rand() % 10);
    printf(search(a, N, el) ? "Found it!\n" : "It ain't there :(\n");

    return 0;
}

bool search(const int a[], int n, int key) {
    for (const int *p = a; p - a < n; p++)
        if (*p == key) return true;
    return false;
}
