#include <stdio.h>

int main(void) {
    int de, i;
    float e;

    printf("Enter a fucking n, you muppet: ");
    scanf("%d", &n);

    for (e = 1.0f, de = 1, i = 1; i <= n; i++, de *= i)
        e += 1.0f/de;
    printf("e is fucking %f\n", e);

    return 0;
}
