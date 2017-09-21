#include <stdio.h>

#define ERROR(...) fprintf(stderr, __VA_ARGS__)

int main(void) {
    ERROR("Humans suck\n");

    return 0;
}
