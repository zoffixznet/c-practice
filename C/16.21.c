#include <stdio.h>

int main(void) {
    enum { NUL, SOH, STX, ETX };
    printf("%d, %d, %d, %d\n", NUL, SOH, STX, ETX); // 0, 1, 2, 3

    enum { VT = 11, FF, CR };
    printf("%d, %d, %d\n", VT, FF, CR); // 11, 12, 13

    enum { SO = 14, SI, DLE, CAN = 24, EM };
    printf("%d, %d, %d, %d, %d\n", SO, SI, DLE, CAN, EM); // 14, 15, 16, 24, 25

    enum { ENQ = 45, ACK, BEL, LF = 37, ETB, ESC };
    printf("%d, %d, %d, %d, %d, %d\n", ENQ, ACK, BEL, LF, ETB, ESC); // 45, 46, 47, 37, 38, 39

    return 0;
}
