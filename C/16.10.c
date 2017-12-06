#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct { int x, y; } Point;
typedef struct { Point tl, br; } Rect;

long rect_area(const Rect r);
Point rect_center(const Rect r);
Rect rect_move(const Rect r, int x, int y);
bool is_within(const Rect r, const Point p);

int main(void) {
    Rect r = { .tl = (Point){.x = 0, .y = 0}, .br = (Point){.x = 100, .y = 200} };

    printf("Area of r is %ld\n", rect_area(r));

    Point center = rect_center(r);
    printf("Center of r is %d, %d\n", center.x, center.y);

    Rect moved = rect_move(r, 24, 42);
    printf("Moved rectangle is at (%d, %d), (%d, %d)\n",
        moved.tl.x, moved.tl.y, moved.br.x, moved.br.y);

    printf("Point is %s r\n",     is_within(r,     (Point){111, 222}) ? "INSIDE" : "outside");
    printf("Point is %s moved\n", is_within(moved, (Point){111, 222}) ? "INSIDE" : "outside");
    return 0;
}

long rect_area(const Rect r) {
    return abs(r.br.x - r.tl.x) * abs(r.br.y - r.tl.y);
}

Point rect_center(const Rect r) {
    return (Point){
        .x = (r.br.x - r.tl.x)/2,
        .y = (r.br.y - r.tl.y)/2
    };
}

Rect rect_move(const Rect r, int x, int y) {
    return (Rect){
        .tl = (Point){ .x = r.tl.x + x, .y = r.tl.y + y },
        .br = (Point){ .x = r.br.x + x, .y = r.br.y + y }
    };
}

bool is_within(const Rect r, const Point p) {
    return r.tl.x <= p.x && r.br.x >= p.x
        && r.tl.y <= p.y && r.br.y >= p.y ? true : false;
}
