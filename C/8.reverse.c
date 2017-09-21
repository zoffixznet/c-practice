#include <stdio.h>

#define N 10

int main(void) {
    int a[N];

    printf("Enter %d fucking numbers: ", N);
    for (int i = 0; i < N; i++)
        if (scanf("%d", &a[i]) <= 0) return 1;

    printf("In reverse, these fucking numbers are:");
    for (int i = N-1; i >= 0; i--)
        printf(" %d", a[i]);
    putchar('\n');

    return 0;
}
