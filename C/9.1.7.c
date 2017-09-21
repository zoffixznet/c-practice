#include <stdio.h>

int f(int a, int b) {
    return a+b;
}

int main(void) {
    int i;
    double x;
    i = f(83, 12);
    x = f(83, 12);
    printf("DONE! `%f` `%d`\n", x, i);
    i = f(3.15, 9.28);
    x = f(3.15, 9.28);
    printf("DONE! `%f` `%d`\n", x, i);
    return 0;
}
