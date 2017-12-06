#include <stdio.h>
#include <stdlib.h>

struct color {
    int r, g, b;
};

int main(void) {
    const struct color MAGENTA = { 255, 0, 255 };
    const struct color MAGENTA2 = { .r = 255, .b = 255 };

    printf("%d, %d, %d\n", MAGENTA.r, MAGENTA.g, MAGENTA.b);
    printf("%d, %d, %d\n", MAGENTA2.r, MAGENTA2.g, MAGENTA2.b);
    return 0;
}
