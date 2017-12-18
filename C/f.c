#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline double z(double a, double b) {
    return 2*a*b;
}

int main(void) {
    double d, dd;
    printf("Enter a fucking double: ");
    if (scanf("%lf", &d) < 1) exit(1);
    for (unsigned int i = 0; i < UINT_MAX; i++)
        dd = z(d, d-1);
    printf("Result: %g\n", dd);
    return 1;
}
