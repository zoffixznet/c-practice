#include <stdio.h>

int main(void) {
    int i, n;

    printf("Enter a fucking number: "); scanf("%d", &n);

    i = 1;
    while (i < n) {
        printf("%20d%20d\n", i, i*i);
        i++;
    }

    printf("Happy now?\n");

    return 0;
}
