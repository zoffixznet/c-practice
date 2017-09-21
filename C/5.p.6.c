#include <stdio.h>

int main(void) {
    int d[12];

    printf("Enter the UPC: x-xxxxx-xxxxx-x: ");
    scanf("%1d-%1d%1d%1d%1d%1d-%1d%1d%1d%1d%1d-%1d",
        &d[0],
        &d[1], &d[2], &d[3], &d[4], &d[5],
        &d[6], &d[7], &d[8], &d[9], &d[10],
        &d[11]);

    printf(
        (9 - (
            3*(d[0] + d[2] + d[4] + d[6] + d[8] + d[10])
            + (d[1] + d[3] + d[5] + d[7] + d[9])
            - 1
        ) % 10) == d[11]
        ? "VALID\n" : "NOT VALID\n"
    );

    return 0;
}
