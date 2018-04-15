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
    unsigned int frac: 23;
    unsigned int exp:   8;
    unsigned int sign:  1;
} Float;

typedef union {
    Float F;
    float f;
} FloatView;

int main(void) {
    FloatView v;
    v.F.sign = 0;
    v.F.exp = 127;
    v.F.frac = 2;
    PRINTB(v);
    printf("%.18f\n", v.f);
    return 0;

    // it clears the first set LSB
}
