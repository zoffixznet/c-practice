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

#define SHIFT_BIT 1
#define CTRL_BIT  2
#define ALT_BIT   4


int main(void) {
    unsigned char i = 0;
    PRINTB(i);
    if ((i & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0)
        puts("Meows");
    return 0;

    // (a) ~0 sets all bits to 1, left shift by n, ~ flips new zeros to 1s,
    // the rest are zeros:  so it's a way to set n LSB to 1
    // (b) it returns the bitfield from mth to nth bits
}
