#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int r, g, b;
} Color;

Color make_color  (int r, int g, int b);
Color brighten    (const Color c);
Color darken      (const Color c);
void  print_color (const Color c);
int   get_red     (const Color c);
bool  equal_color (const Color c1, const Color c2);

int main(void) {
    puts("Color making");
    print_color(make_color(123, 11, 42));
    print_color(make_color(-123, 300, 42));

    puts("\nBrightening");
    print_color(brighten(make_color(0, 0, 0)));
    print_color(brighten(make_color(2, 2, 2)));
    print_color(brighten(make_color(30, 0, 255)));

    puts("\nDarkening");
    print_color(darken(make_color(0, 0, 0)));
    print_color(darken(make_color(100, 255, 0)));

    puts("\nGet red");
    printf("%d\n", get_red(make_color(100, 255, 0)));
    printf("%d\n", get_red(make_color(42, 13, 40)));

    puts("\nEquality");
    puts(equal_color(
            make_color(255, 255, 0),
            make_color(255, 255, 0)
        ) ? "Equal" : "Not equal");

    puts(equal_color(
            make_color(1, 2, 3),
            make_color(3, 2, 1)
        ) ? "Equal" : "Not equal");
    return 0;
}

Color make_color(int r, int g, int b) {
    return (Color){
        .r = r < 0 ? 0 : r > 255 ? 255 : r,
        .g = g < 0 ? 0 : g > 255 ? 255 : g,
        .b = b < 0 ? 0 : b > 255 ? 255 : b
    };
}

Color brighten(const Color c) {
    if (c.r == 0 && c.g == 0 && c.b == 0)
        return (Color){.r = 3, .g = 3, .b = 3};

    return make_color(
        (c.r < 3 ? 3 : c.r) / .7,
        (c.g < 3 ? 3 : c.g) / .7,
        (c.b < 3 ? 3 : c.b) / .7
    );
}

Color darken(const Color c) {
    return make_color(c.r * .7, c.g * .7, c.b * .7);
}

void print_color(const Color c) {
    printf("%d, %d, %d\n", c.r, c.g, c.b);
}

int get_red(const Color c) {
    return c.r;
}

bool equal_color(const Color c1, const Color c2) {
    return c1.r == c2.r
        && c1.g == c2.g
        && c1.b == c2.b ? true : false;
}
