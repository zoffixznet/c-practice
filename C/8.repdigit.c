#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
    bool a[10] = {false};
    long long num;

    printf("Enter your fucking integer number: ");
    if (scanf("%lld", &num) <= 0) return 1;
    num = abs(num);
    while (num != 0) {
        int d = num % 10;
        if ( a[d]++ ) {
            printf("Digit %d repeats. Fuck off!\n", d);
            return 0;
        }
        num /= 10;
    }

    printf("No repeats. Awesome!\n");

    return 0;
}
