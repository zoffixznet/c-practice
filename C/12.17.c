#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10
#define N   10

long long sum_2d_array (const int a[][LEN], int n);

int main(void) {
    int a[N][LEN];

    srand((unsigned) time(NULL));
    printf("The fucking array is:\n");
    for (int *p = a[0]; p < a[N]; p++) {
        printf("%d ", *p = rand() % 10);
        if ((p + 1 - a[0]) % LEN == 0)
            putchar('\n');
    }

    printf("\nThe fucking sum is %lld\n",
        sum_2d_array((const int (*)[LEN]) a, N));

    return 0;
}

long long sum_2d_array (const int a[][LEN], int n) {
    long long sum = 0;
    for (const int *p = a[0]; p < a[n]; p++)
        sum += *p;
    return sum;
}
