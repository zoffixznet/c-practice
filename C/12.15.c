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

    printf("\nEnter the day of the week to display temp for (1-7): ");
    int d;
    if (scanf("%d", &d) <= 0) exit(1);
    if (d < 1 || d > 7) {
        printf("You're a special kind of stupid. Fuck off!\n");
        exit(1);
    }

    printf("The temps for day %d are:\n", d);
    d--;
    for (int *p = t[d]; p < &t[d][HOURS]; p++) {
        printf("%d ", *p);
        if ((1 + p - t[0]) % 6     == 0)
            putchar(' ');
    }
    printf("\n\n");

    return 0;
}

bool search(const int a[], int n, int key) {
    for (const int *p = a; p - a < n; p++)
        if (*p == key) return true;
    return false;
}
