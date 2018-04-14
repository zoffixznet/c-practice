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

unsigned short swap_bytes(unsigned short i) {
    return (i << 8) | (i >> 8);
}

int main(void) {
    unsigned short i = 0xFF12;
    PRINTB(i);
    i = swap_bytes(i);
    PRINTB(i);
    return 0;
}
