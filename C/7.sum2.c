#include <stdio.h>

int main(void) {
    long long n, sum = 0;

    printf("Enter a bunch of fucking numbers, terminating with zero: ");
    scanf("%lld", &n);
    while (n) {
        sum += n;
        scanf("%lld", &n);
    }
    printf("The fucking sum is %lld\n", sum);

    return 0;
}
