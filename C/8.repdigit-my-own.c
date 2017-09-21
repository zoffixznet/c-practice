#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int d;
    bool a[10] = {false};

    printf("Enter your fucking integer number: ");
    while ((d = getchar() - '0') >= 0 && d <= 9) {
        if ( a[d]++ ) {
            printf("Digit %d repeats. Fuck off!\n", d);
            return 0;
        }
    }

    printf("No repeats. Awesome!\n");

    return 0;
}
