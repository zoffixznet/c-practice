#include <stdio.h>

double median(double x, double y, double z) {
    if ((y <= x && x <= z) || (z <= x && x <= y)) return x;
    if ((x <= y && y <= z) || (z <= y && y <= x)) return y;
    return z;
}

int main(void) {
    printf("%g\n", median(42, 1, 70));
    printf("%g\n", median(42, 70, 1));

    printf("%g\n", median(1, 42, 70));
    printf("%g\n", median(70, 42, 1));

    printf("%g\n", median(1, 70, 42));
    printf("%g\n", median(70, 1, 42));

    printf("%g\n", median(42, 42, 42));
    printf("%g\n", median(42, 42, 70));
    printf("%g\n", median(42, 42, 1));
    return 0;
}
