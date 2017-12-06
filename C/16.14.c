#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { RECTANGLE, CIRCLE } ShapeKind;
typedef struct { int x, y; } Point;
typedef struct {
    ShapeKind kind;
    Point center;
    union {
        struct { int height, width; } rectangle;
        struct { int radius;        } circle;
    } u;
} Shape;

void shape_print(const Shape s);
long shape_area(const Shape s);
Shape shape_move(Shape s, int x, int y);
Shape shape_scale(Shape s, double c);

int main(void) {
    Shape s_rect = { RECTANGLE, (Point){100, 200}, {.rectangle = {12, 24}} };
    Shape s_circ = { CIRCLE,    (Point){20,  400}, {.circle    = {42    }} };

    shape_print(s_rect);
    shape_print(s_circ);

    printf("Area of s_rect is %ld\n", shape_area(s_rect));
    printf("Area of s_circ is %ld\n", shape_area(s_circ));

    puts("\nMoving");
    shape_print(shape_move(s_rect, 11, 22));
    shape_print(shape_move(s_circ, 3, 44));
    shape_print(s_rect);
    shape_print(s_circ);

    puts("\nScaling");
    shape_print(shape_scale(s_rect, .3));
    shape_print(shape_scale(s_circ, .3));
    shape_print(shape_scale(s_rect, 3));
    shape_print(shape_scale(s_circ, 3));

    return 0;
}

void shape_print(const Shape s) {
    s.kind == RECTANGLE
        ? printf("Rectangle %d x %d, centered at (%d, %d)\n",
            s.u.rectangle.height, s.u.rectangle.width, s.center.x, s.center.y)
        : printf("Circle radius %d, centered at (%d, %d)\n",
            s.u.circle.radius, s.center.x, s.center.y);
}

long shape_area(const Shape s) {
    return s.kind == RECTANGLE
        ? s.u.rectangle.width * s.u.rectangle.height
        : s.u.circle.radius   * s.u.circle.radius * 3.141592;
}

Shape shape_move(Shape s, int x, int y) {
    s.center.x += x;
    s.center.y += y;
    return s;
}

Shape shape_scale(Shape s, double c) {
    if (s.kind == RECTANGLE) {
        s.u.rectangle.height *= c;
        s.u.rectangle.width  *= c;
    }
    else
        s.u.circle.radius *= c;

    return s;
}
