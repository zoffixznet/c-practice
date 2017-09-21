#include <stdio.h>

int main(void) {
    unsigned long long n, de, i;
    double e;

    printf("Enter a fucking n, you muppet: ");
    scanf("%d", &n);

    for (e = 1.0, de = 1, i = 1; i <= n; i++, de *= i)
        e += 1.0/de;
    printf("e is fucking %.30f\n", e);

    return 0;
}
