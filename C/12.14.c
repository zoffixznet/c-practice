#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define DAYS 7
#define HOURS 24

bool search(const int a[], int n, int key);

int main(void) {
    int t[DAYS][HOURS];

    srand((unsigned) time(NULL));
    printf("The array is:\n");
    for (int *p = t[0]; p < t[DAYS]; p++) {
        printf("%d ", *p = rand()%10 + 25);

        if      ((1 + p - t[0]) % HOURS == 0)
            putchar('\n');
        else if ((1 + p - t[0]) % 6     == 0)
            putchar(' ');
    }

    printf(search(t[0], DAYS*HOURS, 32)
        ? "Found it!\n" : "It ain't there :(\n");

    return 0;
}

bool search(const int a[], int n, int key) {
    for (const int *p = a; p - a < n; p++)
        if (*p == key) return true;
    return false;
}
