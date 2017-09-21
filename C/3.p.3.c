#include <stdio.h>

int main(void) {
    int g1, g2, g3, g4, g5;
    // 978-0-393-97950-3
    printf("Enter an ISBN: ");
    scanf("%d-%d-%d-%d-%d", &g1, &g2, &g3, &g4, &g5);

    printf("GS1 prefix: %d\n", g1);
    printf("Group identifier: %d\n", g2);
    printf("Publisher code: %d\n", g3);
    printf("Item number: %d\n", g4);
    printf("Check digit: %d\n", g5);
    return 0;
}
