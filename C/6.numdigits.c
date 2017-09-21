#include <stdio.h>

int main(void) {
    int n, digits = 0;

    printf("Enter a non-negative number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("I said NON-NEGATIVE, fuckface!\n");
        return 1;
    }

    do digits++; while ((n /= 10) > 0);

    printf(digits == 1 ? "There is %d fucking digit\n"
                       : "There are %d fucking digits\n", digits);

    return 0;
}
