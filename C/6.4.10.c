#include <stdio.h>

int main(void) {
    int i = 0, n = 0;

    while (i < 10) {
        if (++n % 3 != 0) continue;
        printf("%d ", n);
        i++;
    }
    printf("\n");

    i = 0; n = 0;
    while (i < 10) {
        if (++n % 3 != 0) goto hell;
        printf("%d ", n);
        i++;
        hell: ;
    }
    printf("\n");

    return 0;
}
