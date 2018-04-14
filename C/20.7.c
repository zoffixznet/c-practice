#include <stdio.h>
#include <inttypes.h>

#define PRINTB(x) (print_binary((&x), sizeof(x)))
void print_binary(void *start, size_t size) {
    unsigned char *p = start;
    int line = 0;
    while (size--) {
        for (int i = 7; i >= 0; i--) {
            if (i == 3) putchar('|');
            putchar(*p & 1 << i ? '1' : '0');
        }
        printf("  ");
        p++;
        if ((++line % 10) == 0) putchar('\n');
    }
    putchar('\n');
}

unsigned int rotate_left(unsigned int i, int n) {
    return i << n | i >> (sizeof(i)*8 - n);
}
unsigned int rotate_right(unsigned int i, int n) {
    return i >> n | i << (sizeof(i)*8 - n);
}

int main(void) {
    unsigned int i = 1213124214;
    PRINTB(i);
    i = rotate_left(i, 7);
    PRINTB(i);
    i = rotate_right(i, 7);
    PRINTB(i);
    return 0;
}
