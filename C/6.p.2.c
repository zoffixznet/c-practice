#include <stdio.h>

int main(void) {
    int m, n, rem;
    printf("Enter two fucking integers: ");
    scanf("%d%d", &m, &n);

    while (n != 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    printf("GCD is fucking %d\n", m);

    return 0;
}
