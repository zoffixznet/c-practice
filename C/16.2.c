#include <stdio.h>

int main(void) {
    struct meows {
        double real, imaginary;
    } c1 = { 42.0, 1.0 }, c2 = { 1.3, 0.5 }, c3;

    // c1 = c2; // (c)

    // (d)
    c3.real      = c2.real      + c1.real;
    c3.imaginary = c2.imaginary + c1.imaginary;

    struct meows foos[3] = {c1, c2, c3};
    for (int i = 0; i < 3; i++)
        printf("%g %g\n", foos[i].real, foos[i].imaginary);
}
