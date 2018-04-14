#include <stdio.h>

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
    struct foo {
        int a: 1, b: 1, c: 1, d: 1, e: 1, f: 1, g: 1, h: 1, i: 1, j: 1;
        unsigned int a1: 1, a2: 1, a3: 1, a4: 1;
        const char *z;
    } bar;
    print_binary(&bar, sizeof(bar));
    return 0;
}
