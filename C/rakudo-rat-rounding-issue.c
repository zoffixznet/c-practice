#include <stdio.h>
#include <math.h>

double to_num(int whole_part, int fract_part, int exponent);
int chars_of(int n);

int main(void) {
    //  say  .1e0  +  .2e0  ==  .3e0;  # False
    printf(" .1e0  +  .2e0  ==  .3e0 ; # %s\n",
        to_num(0, 1,  0) + to_num(0, 2,  0) == to_num(0, 3,  0) ? "True" : "False");

    //  say 1.0e-1 + 2.0e-1 == 3.0e-1; # True;
    printf("1.0e-1 + 2.0e-1 == 3.0e-1; # %s\n",
        to_num(1, 0, -1) + to_num(2, 0, -1) == to_num(3, 0, -1) ? "True" : "False");

    return 0;
}

double to_num(int whole_part, int fract_part, int exponent) {
    double fract_mult, num;

    whole_part *= 10*chars_of(fract_part);
    whole_part += fract_part;
    fract_mult  = 10*chars_of(fract_part);

    num = whole_part / fract_mult;
    if (num)
        num *= pow(10.0, (double) exponent);

    return num;
}

int chars_of(int n) {
    int chars = 1;
    while ((n /= 10) != 0)
        chars++;
    return chars;
}
