#include <stdio.h>

int main(void) {
    int i;

    for (i = 10; i > 1; i /= 2)
        printf("%d ", i++);
    printf("\n");

    // 10 (11)->(5) 5 (6)->(3) 3 (4)->(2) 2 (3)->(1) 1 (2)->(1) 1.... inf

    return 0;
}
