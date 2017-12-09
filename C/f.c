#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 42;
    free(&i);
    return 1;
}
