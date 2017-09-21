#include <stdio.h>

int num_digits(long long n);

int main(void) {
    long long n;
    printf("Enter a long fucking integer: ");
    if (scanf("%lld", &n) <= 0) return 1;
    printf("It has %d fucking digits\n", num_digits(n));
    return 0;
}

int num_digits(long long n) {
    int d = 1;
    while ((n /= 10) != 0)
      d++;
    return d;
}
