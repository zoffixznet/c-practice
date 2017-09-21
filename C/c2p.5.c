#include <stdio.h>
#include <math.h>

int main(void) {
    float x;
    printf("Enter teh x, bruh: "); scanf("%f", &x);
    printf("3x⁵ + 2x⁴ - 5x³ + 7x - 6 = %.2f\n",
        3*powf(x, 5.0f) + 2*powf(x, 4.0f) - 5*powf(x, 3.0f) + 7*x - 6
    );
    return 0;
}
