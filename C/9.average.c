#include <stdio.h>

double average (double a, double b) {
    return (a + b) / 2;
}

int main(void) {
    double x, y, z;

    printf("Enter three fucking doubles: ");
    if (scanf("%lf%lf%lf", &x, &y, &z) <= 0) return 1;
    printf("Average of %g and %g is fucking %g\n", x, y, average(x, y));
    printf("Average of %g and %g is fucking %g\n", y, z, average(y, z));
    printf("Average of %g and %g is fucking %g\n", x, z, average(x, z));

    return 0;
}
