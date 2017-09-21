#include <stdio.h>
#include <math.h>

int main(void) {
    long double n, diff, new_root, root = 1.0;

    printf("Enter a fucking number: ");
    if (scanf("%Lf", &n) <= 0) return 1;

    do {
        new_root = (root + n/root)/2;
        diff = fabs(root - new_root);
        root = new_root;
    } while (diff > .00001*root);

    printf("The square root of %Lg is fucking %Lg\n", n, root);

    return 0;
}
