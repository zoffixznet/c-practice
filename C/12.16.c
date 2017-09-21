#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define DAYS 7
#define HOURS 24

int find_largest(int p[], int n);

int main(void) {
    int t[DAYS][HOURS];

    srand((unsigned) time(NULL));
    printf("The array is:\n");
    for (int *p = t[0]; p < t[DAYS]; p++) {
        printf("%02d ", *p = rand()%99);

        if      ((1 + p - t[0]) % HOURS == 0)
            putchar('\n');
        else if ((1 + p - t[0]) % 6     == 0)
            putchar(' ');
    }

    printf("\nLargest temps for each day are:\n");
    for (int (*p)[HOURS] = t; p < &t[DAYS]; p++)
        printf("%d\n", find_largest(*p, HOURS));

    return 0;
}

int find_largest(int p[], int n) {
    int largest = *p++;
    while (--n > 0)
        if (largest < *p++)
            largest = *(p-1);
    return largest;
}
