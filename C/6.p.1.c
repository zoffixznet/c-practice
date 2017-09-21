#include <stdio.h>

int main(void) {
    float n, max = 0;

    do {
        printf("Enter a fucking number: ");
        scanf("%f", &n);
        if (n > max) max = n;
    } while (n != 0);
    printf("The largest fucking number is %g\n", max);

    return 0;
}
