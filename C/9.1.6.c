#include <stdio.h>

int digit(long long n, int d);

int main(void) {
    long long n;
    int d;
    printf("Enter a long fucking integer: ");
    if (scanf("%lld", &n) <= 0) return 1;
    printf("And which fucking digit do ya want? ");
    if (scanf("%d", &d) <= 0) return 1;
    printf("The %dth fucking digit is %d\n", d, digit(n, d));
    return 0;
}

int digit(long long n, int d) {
    while (--d && (n /= 10) != 0)
      ;
    return n % 10;
}
