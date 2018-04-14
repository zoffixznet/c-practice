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

#define MK_COLOR(r, g, b) ((uint32_t) (r) << 16 | (g) << 8 | (b))
#define GET_BLUE(c)  ( (c)        & 0xFF)
#define GET_GREEN(c) (((c) >> 8)  & 0xFF)
#define GET_RED(c)   (((c) >> 16) & 0xFF)

int main(void) {
    uint32_t c = MK_COLOR(255,100,12);
    PRINTB(c);
    printf("%" PRIu32 "\n", c);
    printf("%d\n", GET_RED(c));
    printf("%d\n", GET_GREEN(c));
    printf("%d\n", GET_BLUE(c));
    return 0;
}
