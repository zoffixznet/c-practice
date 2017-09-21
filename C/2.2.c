#include <stdio.h>

#define INCHES_PER_POUND 166.0f

int main(void) {
    float height, length, width;
    printf("Enter height (inches): "); scanf("%f", &height);
    printf("Enter length (inches): "); scanf("%f", &length);
    printf("Enter width  (inches): "); scanf("%f", &width );

    printf("Dimensions: %f\" x %f\" x %f\"\n", height, length, width);
    printf("Volume: %f in²\n", height * length * width);
    printf("Dimensional weight: %flb\n",
        (height * length * width) / INCHES_PER_POUND
    );

    return 0;
}
