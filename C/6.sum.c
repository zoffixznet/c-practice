#include <stdio.h>

int main(void) {
    int n, sum = 0;

    printf("Enter a bunch of fucking numbers, terminating with zero: ");
    scanf("%d", &n);
    while (n) {
        sum += n;
        scanf("%d", &n);
    }
    printf("The fucking sum is %d\n", sum);

    return 0;
}
