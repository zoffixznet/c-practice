#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, j;
    char s[10000];

    printf("Enter fucking string '12abc34 56def78': ");
    if (scanf("%d%s%d", &i, s, &j) <= 0) {
        puts("Fucked over!");
        exit(1);
    }
    printf("\n'%d'\n'%s'\n'%d'\n", i, s, j);
    // 12abc34 56def78
    // '12'
    // 'abc34'
    // '56'

    return 0;
}
