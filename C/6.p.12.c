#include <stdio.h>

int main(void) {
    float e, term, eps;

    printf("Enter a fucking ε: ");
    scanf("%f", &eps);

    e = 1.0f;
    for (int i = 1, de = 1; ; de *= ++i) {
        term = 1.0f/de;
        if (term == 1.0/.0f || term < eps) break;
        e += term;
    }
    printf("e is fucking %f\n", e);

    return 0;
}
