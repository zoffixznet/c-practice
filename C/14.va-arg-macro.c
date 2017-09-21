#include <stdio.h>

#define TESTO(huh, i, ...) ((huh) \
    ? printf("The '%s' is false when i is %d\n", #huh, i) \
    : printf(__VA_ARGS__, i))

int main(void) {
    for (int i = 0; i < 10; i++)
        TESTO(i > 5, i, "%d is too fucking small\n");
    return 0;
}
