#include <stdio.h>

int gcd(int m, int n);

int main(void) {
    int m, n;
    printf("Enter two fucking integers: ");
    if (scanf("%d%d", &m, &n) <= 0) return 0;
    printf("GCD is fucking %d\n", gcd(m, n));
    return 0;
}

int gcd(int m, int n) {
    int rem;

    while (n != 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}
