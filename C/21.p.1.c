#include <stdio.h>
#include <stddef.h>

int main(void) {
    struct foo {
        unsigned int flag:  1;
        long long int foo;
        float meows;
    };
    printf("%zu\n", offsetof(struct foo, meows));
    // s.flag = 1;
    // PRINTB(s);
    // printf("%d\n", s.flag);
    return 0;
}
