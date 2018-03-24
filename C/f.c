#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline double z(double a, double b) {
    return 2*a*b;
}

int main(void) {
    double z = 0.219947518065601987e0;
    printf("%.17g\n", z);
    return 1;
}
