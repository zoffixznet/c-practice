#include <stdio.h>
#include <stdlib.h>

void *zofalloc (size_t n);

int main(void) {
    int *i = zofalloc(sizeof(*i));
    *i = 42;
    printf("Allocated int: %d\n", *i);

    double *d = zofalloc(sizeof(*d));
    *d = 123.45;
    printf("Allocated double: %lf\n", *d);

    double *z = zofalloc(1000000000000000);
    *z = 123.45;
    printf("Allocated huge double: %lf\n", *z);

    return 1;
}

void *zofalloc (size_t n) {
    void *p = malloc(n);
    if (p) return p;
    printf("Could not allocate %zu bytes of memory. Fuck off!\n", n);
    exit(1);
}
