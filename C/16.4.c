#include <stdio.h>

typedef struct {
    double real, imaginary;
} Complex;

Complex complex(double re, double im);
Complex add_complex(Complex c1, Complex c2);

int main(void) {
    Complex c = complex(42.0, 10.5), c2 = complex(142.0, 12.5),
        res = add_complex(c, c2);
    printf("%g+%gi\n", res.real, res.imaginary);
}

Complex complex(double re, double im) {
    Complex c;
    c.real = re;
    c.imaginary = im;
    return c;
}

Complex add_complex(Complex c1, Complex c2) {
    Complex res;
    res.real = c1.real + c2.real;
    res.imaginary = c1.imaginary + c2.imaginary;
    return res;
}
