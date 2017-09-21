#include <stdio.h>
#include <stdlib.h>

double calc_it(double x) {
    return (((3*x + 2)*x - 5)*x*x - x + 7)*x - 6;
}

int main(void) {
    double x;

    printf("Enter the value for x:\n");
    if (scanf("%lf", &x) <= 0) exit(1);

    printf("The result of 3x⁵+2x⁴-5x³-x²+7x-6 is: %g\n", calc_it(x));

    return 0;
}
