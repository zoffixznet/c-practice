#include <stdio.h>
#include <stdlib.h>

#define SCANF(n, ...) if (scanf(__VA_ARGS__) <= n) { puts("Fuck you!"); exit(1); }

#define CUBE(x) ((x)*(x)*(x))
#define REM(x)  ((x)%4)
#define P(x,y)  ((x)*(y) > 100)

int main(void) {
    int i;
    printf("Enter a fucking integer: ");
    SCANF(0, "%d", &i);
    printf("The %d cubed if fucking %d\n", i, CUBE(i));
    printf("The remained of %d divided by 4 is fucking %d\n", i, REM(i));
    printf("The %d multiplied by remainder of %d divided by 4 is fucking %s than 100\n",
        i, REM(i), P(i,REM(i)) ? "larger" : "not larger");

    return 0;
}
