#include <stdio.h>

int main(void)
{
    char   c = '\1';
    short  s = 2;
    int    i = -3;
    long   m = 5;
    float  f = 6.5f;
    double d = 7.5;

    printf("int      -3 %4d\n", c*i);
    printf("long      7 %4ld\n", s+m);
    printf("float   6.5 %4g\n", f/c);
    printf("double 3.75 %4g\n", d/s);
    printf("double   -1 %4g\n", f-d);
    printf("int       6 %4d\n", (int)f);

    return 0;
}
