#include <stdio.h>

struct complex {
    double real, imaginary;
};

struct complex complex(double re, double im);
struct complex add_complex(struct complex c1, struct complex c2);

int main(void) {
    struct complex c = complex(42.0, 10.5), c2 = complex(142.0, 12.5),
        res = add_complex(c, c2);
    printf("%g+%gi\n", res.real, res.imaginary);
}

struct complex complex(double re, double im) {
    struct complex c;
    c.real = re;
    c.imaginary = im;
    return c;
}

struct complex add_complex(struct complex c1, struct complex c2) {
    struct complex res;
    res.real = c1.real + c2.real;
    res.imaginary = c1.imaginary + c2.imaginary;
    return res;
}
