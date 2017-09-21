#include <stdio.h>
#include <stdlib.h>

#define DOUBLE(x) 2*x
#define FIXED(x)  (2*(x))

int main(void) {
    printf("%d\n", DOUBLE(1+2)); // 4
    printf("%d\n", 4/DOUBLE(2)); // 4

    printf("%d\n", FIXED(1+2)); // 6
    printf("%d\n", 4/FIXED(2)); // 1
    return 0;
}
