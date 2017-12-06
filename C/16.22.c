#include <stdio.h>

int main(void) {
    enum chest_pieces { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

    const int pieces1[6] = {200, 9, 5,  3, 3, 1};
    const int pieces2[6] = {
        [KING  ] = 200, [QUEEN ] = 9, [ROOK] = 5,
        [BISHOP] = 3,   [KNIGHT] = 3, [PAWN] = 1
    };

    for (int i = 0; i < 6; i++)
        printf("%3d | %3d\n", pieces1[i], pieces2[i]);

    return 0;
}
