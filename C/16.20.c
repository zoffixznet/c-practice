#include <stdio.h>

int main(void) {
    enum { NORTH, SOUTH, EAST, WEST } direction = SOUTH;

    int x = 0, y = 0;
    switch (direction) {
        case NORTH: y--; break;
        case SOUTH: y++; break;
        case WEST:  x--; break;
        case EAST:  x++; break;
    }
    printf("%d, %d, %d\n", direction, x, y);

    return 0;
}
