#include <stdio.h>
#include <stdlib.h>

#define AVG(x,y) (x+y)/2
#define AVGFIXED(x,y) (((x)+(y))/2)

#define AREA(x,y) (x)*(y)
#define AREAFIXED(x,y) ((x)*(y))

int main(void) {
    printf("%g\n", 4.0/AVG(4,2));      // ⅓
    printf("%g\n", 4.0/AVGFIXED(4,2)); // 1⅓

    printf("%g\n", 4.0/AREA(4,2));      // 2
    printf("%g\n", 4.0/AREAFIXED(4,2)); // .5

    return 0;
}
