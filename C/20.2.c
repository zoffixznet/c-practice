#include <stdio.h>

#define PRINTB(x) print_binary((&x), sizeof(x))
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

int main(void) {
    unsigned char b = 0;
    for (int i = 0; i < 10; i++) {
        PRINTB(b);
        b ^= 1 << 3;
    }
    return 0;
}
