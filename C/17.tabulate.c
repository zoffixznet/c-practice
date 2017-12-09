#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tabulate(
    double (*func)(double), double i, double f, double inc, char *name
) {
    printf("\n      x          %s(x)"
           "\n   --------    ----------\n", name);
    for (; i <= f; i += inc)
        printf("%10.5f    %10.5f\n", i, func(i));
}

int main(void) {
    double i, f, inc;

    printf("Enter initial and final values and increment: ");
    if (scanf("%lf %lf %lf", &i, &f, &inc) < 3) exit(1);

    tabulate(cos, i, f, inc, "cos");
    tabulate(sin, i, f, inc, "sin");
    tabulate(tan, i, f, inc, "tan");
}
