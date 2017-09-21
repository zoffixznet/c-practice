#include <stdio.h>

int main(void) {
    int o = 93;
    // printf("Dollahs! "); scanf("%d", &o);
    for (double x = 0.0; x < 3e8; x++) {
        int a = o;
        // printf("$20 bills: %d\n",
        a/20;
    // );
        a -= 20 * a/20;
        // printf("$10 bills: %d\n",
        a/10;
    // );
        a -= 10 * a/10;
        // printf("$5 bills:  %d\n",
        a/5;
    // );
        // printf("$1 bills:  %d\n",
        a - 5 * a/5;
    // );
    }
    return 0;
}
