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

typedef struct {
    unsigned int sign:  1;
    unsigned int exp:   8;
    unsigned int frac: 23;
} Float;

typedef union {
    Float F;
    float f;
} FloatView;

int main(void) {
    FloatView v;
    v.f = 12e20;
    PRINTB(v.F.sign);
    PRINTB(v.F.exp);
    PRINTB(v.F.frac);

    return 0;

    // it clears the first set LSB
}
