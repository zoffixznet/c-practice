#include <stdio.h>

int main(void) {
    long n;
    printf("Enter number of squares you wanna see:");
    scanf("%d", &n);

    for (long i = 1; i <= n; i++)
        printf("%20ld%20ld\n", i, i*i);

    // int   = 46341 = 32bit
    // short = 182   = 16bit

    return 0;
}
