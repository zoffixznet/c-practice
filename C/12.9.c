#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

double inner_product(double *a, double *b, int n);

int main(void) {
    double a[N], b[N];

    srand((unsigned) time(NULL));

    printf("Array A is:");
    for (double *p = a; p < &a[N]; p++)
        printf(" %g", *p = rand()%10 + (rand()%100)/100.0f);
    printf("\nArray B is:");
    for (double *p = b; p < &b[N]; p++)
        printf(" %g", *p = rand()%10 + (rand()%100)/100.0f);

    printf("\nInner product is fucking: %g\n", inner_product(a, b, N));
    return 0;
}

double inner_product(double *a, double *b, int n) {
    double product = 0;
    while (n-- > 0)
        product += *a++ * *b++;
    return product;
}
