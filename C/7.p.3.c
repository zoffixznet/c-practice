#include <stdio.h>

int main(void) {
    double n, sum = 0.0;

    printf("Enter a bunch of fucking numbers, terminating with zero: ");
    scanf("%lf", &n);
    while (n) {
        sum += n;
        scanf("%lf", &n);
    }
    printf("The fucking sum is %lf\n", sum);

    return 0;
}
