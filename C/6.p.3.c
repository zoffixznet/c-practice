#include <stdio.h>

int gcd(int m, int n);

int main(void) {
    int nu, de, nude_gcd;

    printf("Enter a fucking fraction: ");
    scanf("%d/%d", &nu, &de);

    nude_gcd = gcd(nu, de);
    nu /= nude_gcd;
    de /= nude_gcd;

    printf("Lowest fucking terms are: %d/%d\n", nu, de);
    return 0;
}

int gcd(int m, int n) {
    int rem;
    while (n != 0) {
        rem = m % n;
        m   = n;
        n   = rem;
    }
    return m;
}
