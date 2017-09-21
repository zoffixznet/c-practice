#include <stdio.h>

int main(void) {
    int g1, g2, g3;
    printf("Enter a phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d", &g1, &g2, &g3);
    printf("You entered: %d.%d.%d\n", g1, g2, g3);
    return 0;
}
