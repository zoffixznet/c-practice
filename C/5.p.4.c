#include <stdio.h>

int main(void) {
    float knots;

    printf("Enter knots, bruh: ");
    scanf("%f", &knots);

    if (knots < 0.0f)
        printf("Bullshit!\n");
    else if (knots < 1.0f)
        printf("Calm\n");
    else if (knots <= 3.0f)
        printf("Light air\n");
    else if (knots <= 27.0f)
        printf("Breeze\n");
    else if (knots <= 47.0f)
        printf("Gale\n");
    else if (knots <= 63.0f)
        printf("Storm\n");
    else
        printf("Hurricane\n");

    return 0;
}
