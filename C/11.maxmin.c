#include <stdio.h>
#include <stdlib.h>

#define N 10

void maxmin (int a[], int n, int *max, int *min);

int main(void) {
    int a[N], max, min;

    printf("Enter %d fucking integers: ", N);
    for (int i = 0; i < N; i++)
        if (scanf("%d", &a[i]) <= 0) exit(1);

    maxmin(a, N, &max, &min);
    printf("The minimum fucking number is %d\n", min);
    printf("The maximum fucking number is %d\n", max);

    return 0;
}

void maxmin (int a[], int n, int *max, int *min) {
    *max = *min = a[0];
    for (int i = 1; i < n; i++)
        if      (a[i] < *min) *min = a[i];
        else if (a[i] > *max) *max = a[i];
}
