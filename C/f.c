#include <stdio.h>
#include <math.h>
int main(void) {
    printf("%.16f    %.16f\n", 1e0+6e-15, nextafter(1e0, 2e0));
}

// OUTPUT: More
