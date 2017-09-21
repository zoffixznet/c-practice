#include <stdio.h>

int main(void) {
    int a[5] = { 1, 2, 3, 4, 5 }, *p = a;

    // printf("%d\n", p == a[0]); Illegal
    printf("%d\n", p == &a[0]); // 1
    printf("%d\n", *p == a[0]); // 1
    printf("%d\n", p[0] == a[0]); // 1

    return 0;
}
