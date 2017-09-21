#include <stdio.h>

int main(void) {
    long n;

    printf("Enter number of squares you wanna see:");
    scanf("%d", &n); getchar();

    for (long i = 1; i <= n; i++) {
        printf("%20ld%20ld\n", i, i*i);
        if (i % 24) continue;

        printf("Press fucking ENTER to continue");
        while (getchar() != '\n')
            ;
    }

    return 0;
}
