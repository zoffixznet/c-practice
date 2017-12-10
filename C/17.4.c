#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    struct point { int x, y; };
    struct rectangle { struct point upper_left, bottom_right; };
    struct rectangle *p;

    p = malloc(sizeof(struct rectangle));
    if (!p) {
        puts("Fuck!");
        exit(1);
    }
    *p = (struct rectangle){{10, 25}, {20, 15}};

    printf("TL: (%d, %d)\nBR: (%d, %d)\n",
        p->upper_left.x,   p->upper_left.y,
        p->bottom_right.x, p->bottom_right.y);
    free(p);

    return 0;
}
