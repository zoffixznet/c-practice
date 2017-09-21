#include <stdio.h>

float volume (float radius);

int main(void) {
    float r;
    printf("Enter teh radiooos, bruh: "); scanf("%f", &r);
    printf("The volume of a sphere with radius %f is %f\n", r, volume(r));
    return 0;
}

float volume (float r) {
    return 4.0f / 3.0f * 3.14159265358979 *r*r*r;
}
