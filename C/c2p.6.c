#include <stdio.h>
#include <math.h>

int main(void) {
    float x;
    printf("Enter teh x, bruh: "); scanf("%f", &x);
    printf("3x⁵ + 2x⁴ - 5x³ - x² + 7x - 6 = %.2f\n",
        (((((3*x + 2)*x - 5)*x - 1)*x + 7)*x - 6
    );
    return 0;
}
