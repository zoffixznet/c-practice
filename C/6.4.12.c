#include <stdio.h>

int main(void) {
    int d, n;

    printf("Enter a number to test for primality: ");
    scanf("%d", &n);
    for (d = 2; d*d <= n; d++)
        if (n % d == 0)
            break;
    printf("%d is ", n);
    printf(d*d <= n ? "not prime\n" : "prime\n");
    return 0;
}
