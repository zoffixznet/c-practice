#include <stdio.h>

float volume (int radius);

int main(void) {
    int r = 10;
    printf("The volume of a sphere with radius %d is %f\n", r, volume(r));
    return 0;
}

float volume (int r) {
    return 4.0f / 3.0f * 3.14159265358979 *r*r*r;
}
