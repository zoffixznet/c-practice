#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int sum_array (const int a[], int n);

int main(void) {
    int a[N];

    srand((unsigned) time(NULL));
    printf("The array is:");
    for (int i = 0; i < N; i++)
        printf(" %d", a[i] = rand() % 10);
    printf("\nIts sum is %d\n", sum_array(a, N));

    return 0;
}

int sum_array (const int *a, int n) {
    int sum = 0;
    for (const int *p = a; p - a < n; p++)
        sum += *p;
    return sum;
}
