#include <stdio.h>
#include <stdlib.h>

long long power(long x, long p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        long long res = power(x, p/2);
        return res*res;
    }
    else {
        return x * power(x, p-1);
    }
}

int main(void) {
    long n, p;

    printf("Enter your fucking number and the power to raise it to:\n");
    if (scanf("%ld", &n) <= 0) exit(1);
    if (scanf("%ld", &p) <= 0) exit(1);

    printf("%ld**%ld is %lld\n", n, p, power(n, p));

    return 0;
}
