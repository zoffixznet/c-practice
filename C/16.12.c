#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
    struct foo {
        int d;
        char b[4];
        double c;
    };

    union {
        double a;
        struct foo e;
        char f[4];
    } u;

    printf("char   %zu\n", sizeof(char));
    printf("int    %zu\n", sizeof(int));
    printf("double %zu\n", sizeof(double));
    printf("foo    %zu\n", sizeof(struct foo));
    printf("%zu\n", sizeof(u));
    return 0;
}
