#include <stdio.h>

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

#define M(x,y) ((x)^=(y), (y)^=(x), (x)^=(y))

int main(void) {
    unsigned char a = 10, b = 20;
    PRINTB(a);
    PRINTB(b);
    M(a,b);
    PRINTB(a);
    PRINTB(b);
    printf("a = %d; b = %d\n", a, b);
    return 0;
}
