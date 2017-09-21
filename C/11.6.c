#include <stdio.h>
#include <stdlib.h>

#define N 10

void find_two_largest(int a[], int n, int *l1, int *l2);

int main(void) {
    int a[N], l1, l2;

    printf("Enter %d fucking integers: ", N);
    for (int i = 0; i < N; i++)
        if (scanf("%d", &a[i]) <= 0) exit(1);

    find_two_largest(a, N, &l1, &l2);
    printf("The largest fucking number is %d\n", l1);
    printf("The second largest fucking number is %d\n", l2);

    return 0;
}

void find_two_largest(int a[], int n, int *l1, int *l2) {
    *l1 = *l2 = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > *l1) *l1 = a[i];
    for (int i = 1; i < n; i++)
        if (a[i] > *l2 && a[i] != *l1) *l2 = a[i];
}
