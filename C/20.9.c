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

int count_ones(unsigned char i) {
    return ((i & 1 << 7) ? 1 : 0)
         + ((i & 1 << 6) ? 1 : 0)
         + ((i & 1 << 5) ? 1 : 0)
         + ((i & 1 << 4) ? 1 : 0)
         + ((i & 1 << 3) ? 1 : 0)
         + ((i & 1 << 2) ? 1 : 0)
         + ((i & 1 << 1) ? 1 : 0)
         + ((i & 1 << 0) ? 1 : 0);
}


int main(void) {
    unsigned char i = 12;
    PRINTB(i);
    printf("%d has %d ones\n", i, count_ones(i));
    return 0;

    // (a) ~0 sets all bits to 1, left shift by n, ~ flips new zeros to 1s,
    // the rest are zeros:  so it's a way to set n LSB to 1
    // (b) it returns the bitfield from mth to nth bits
}
