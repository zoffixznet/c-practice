#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    double x = 1e-200;
    double y = 1e-200 * x;
    printf("Log of %.17g: %g\n", y, log(y));
    y = -1e-200*x;
    printf("Log of %.17g: %g\n", y, log(-0e0));


    // long long x1 = 99989999999999991, y1 = 100000000000000000,
            //   x2 = 9998999999999999,  y2 = 10000000000000000;
    // double z1 = x1/(double)y1, z2 = x2/(double)y2;
    // printf("%.17g\n", z1);
    // printf("%.17g\n", z2);
    // printf("%d\n", z1 == z2);
    // printf("%.17g\n", 9.998999999999999e0);
    // printf("%d\n", 9.998999999999999e0 == 9.999e0);

    // printf("%.17g\n", atof2("9.9989999999999991e0"));
    // printf("%.17g\n", atof2("9.998999999999999e0"));
    // printf("%.17g\n", atof2("5e-324"));
    // printf("%.17g\n", nextafter(9.998999999999999e0, DBL_MIN));
    // 9.9989999999999991e0
    //  9.998999999999999e0);
}
