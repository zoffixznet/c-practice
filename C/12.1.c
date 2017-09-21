#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[1], *q = &a[5];
    printf("14 = %d\n", *(p+3));
    printf("34 = %d\n", *(q-3));
    printf("4  = %d\n", (int)(q-p));
    printf("True = %s\n", p < q ? "True" : "False");
    printf("False = %s\n", *p < *q ? "True" : "False");
    return 0;
}
