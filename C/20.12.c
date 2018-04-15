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

unsigned short create_short(unsigned char high, unsigned char low) {
    return (high << 8) + low;
}

int main(void) {
    unsigned char i1 = 12;
    unsigned char i2 = 55;
    PRINTB(i1);
    PRINTB(i2);
    unsigned short s = create_short(i1, i2);
    PRINTB(s);
    return 0;

    // (a) ~0 sets all bits to 1, left shift by n, ~ flips new zeros to 1s,
    // the rest are zeros:  so it's a way to set n LSB to 1
    // (b) it returns the bitfield from mth to nth bits
}
