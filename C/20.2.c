#include <stdio.h>

#define PRINTB(x) print_binary((&x), sizeof(x))
void print_binary(void *start, size_t size) {
    unsigned char *p = start;
    int line = 0;
    while (size--) {
        for (int i = 7; i >= 0; i--)
            putchar(*p & 1 << i ? '1' : '0');
        putchar(' ');
        p++;
        if ((++line % 10) == 0) putchar('\n');
    }
    putchar('\n');
}

int main(void) {
    unsigned char i = 0;
    PRINTB(i);
    return 0;
}
