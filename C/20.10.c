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

unsigned int reverse_bits(unsigned int orig) {
    unsigned int reversed = 0;
    size_t max = sizeof(orig)*8;
    for (size_t i = 0; i < max; i++)
        if (orig & 1 << i)
            reversed |= 1 << (max-i-1);
    return reversed;
}


int main(void) {
    unsigned int i = 124335665;
    PRINTB(i);
    i = reverse_bits(i);
    PRINTB(i);
    return 0;

    // (a) ~0 sets all bits to 1, left shift by n, ~ flips new zeros to 1s,
    // the rest are zeros:  so it's a way to set n LSB to 1
    // (b) it returns the bitfield from mth to nth bits
}
