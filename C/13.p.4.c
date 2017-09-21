#include <stdio.h>

int main(int argc, const char **argv) {
    while (--argc)
        printf("%s ", *(argv + argc));
    putchar('\n');
    return 0;
}
