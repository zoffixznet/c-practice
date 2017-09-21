#include <stdio.h>

#define MAX 1000

int main(void) {
    int a[MAX], *p;

    printf("Enter your fucking message:  ");
    for (p = a; p < a + MAX; p++)
        if ((*p = getchar()) == '\n')
            break;

    printf("Fucking reversal is fucking: ");
    while (--p >= a)
        putchar(*p);
    putchar('\n');

    return 0;
}
