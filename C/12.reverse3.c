#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void) {
    int a[N];

    printf("Enter %d fucking integers: ", N);
    for (int *p = a; p < &a[N]; p++)
        if (scanf("%d", p) <= 0) exit(1);

    printf("The numbers in fucking reverse:");
    for (int *p = a + N - 1; p >= a; p--)
        printf(" %d", *p);
    putchar('\n');

    return 0;
}
