#include <stdio.h>
#include <stdbool.h>

bool is_prime (unsigned long long n) {
    unsigned long long int divisor;
    if (n <= 1) return false;
    for (divisor = 2u; divisor * divisor <= n; divisor++)
        if (n % divisor == 0u)
            return false;
    return true;
}

int main(void) {
    unsigned long long n;

    printf("Enter a positive fucking number: ");
    if (scanf("%Lu", &n) <= 0) return 1;

    if (is_prime(n))
        printf("Tis fucking prime\n");
    else
        printf("Tis NOT fucking prime\n");

    return 0;
}
