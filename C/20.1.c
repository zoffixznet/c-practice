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
    unsigned short i, j, k;

    i = 8; j = 9;
    printf("%d\n",  i >> 1  +  j >> 1);  // 0
    printf("%d\n", (i >> 1) + (j >> 1)); // 8

    i = 1;
    printf("%d\n", i & ~i); // 0

    i = 2; j = 1; k = 0;
    printf("%d\n", ~i & j ^ k); // 1
    return 0;
}
