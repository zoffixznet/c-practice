#include <stdio.h>

int main(void) {
    int i, n, sqr;

    printf("Enter a fucking number: ");
    scanf("%d", &n);

    for (i = 1; (sqr = i*i) <= n; i++) {
        if (sqr % 2 != 0) continue;
        printf("%d\n", sqr);
    }

    return 0;
}
