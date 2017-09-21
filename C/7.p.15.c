#include <stdio.h>

int main(void) {
    int n, cur = 1;
    long double fact = 1;

    printf("Enter a fucking number: ");
    if (scanf("%d", &n) <= 0) return 1;

    while (cur <= n) {
        fact *= cur;
        printf("The factorial of %d is fucking %.0Lf\n", cur, fact);
        cur++;
    }

    // short       = 7
    // int         = 12
    // long        = 20
    // long long   = 20
    // float       = 34
    // double      = 170
    // long double = 1754

    return 0;
}
