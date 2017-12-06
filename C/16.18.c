#include <stdio.h>
#include <ctype.h>

typedef enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} Piece;
typedef enum {BLACK, WHITE} Color;

typedef struct {
    Piece piece;
    Color color;
} Square;

// Square board[8][8] = {
//     { {ROOK}, {KNIGHT}, {BISHOP}, {KING},   {QUEEN}, {BISHOP}, {KNIGHT}, {ROOK} },
//     { {PAWN}, {PAWN},   {PAWN},   {PAWN},   {PAWN},  {PAWN},   {PAWN},   {PAWN} },
//     { {}, {}, {}, {},   {}, {}, {}, {} },
//     { {}, {}, {}, {},   {}, {}, {}, {} },
//
//     { {}, {}, {}, {},   {}, {}, {}, {} },
//     { {}, {}, {}, {},   {}, {}, {}, {} },
//     {
//         {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE},
//         {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}
//     },
//     {
//         {ROOK,  WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {KING, WHITE},
//         {QUEEN, WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK, WHITE}
//     },
// };

// Silence bitching about missing initializers
Square board[8][8] = {
    {
        {ROOK,  BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {KING, BLACK},
        {QUEEN, BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK, BLACK}
    },
    {
        {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK},
        {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}
    },
    {
        {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
        {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}
    },
    {
        {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
        {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}
    },
    {
        {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
        {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}
    },
    {
        {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK},
        {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}, {EMPTY, BLACK}
    },
    {
        {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE},
        {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}
    },
    {
        {ROOK,  WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {KING, WHITE},
        {QUEEN, WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK, WHITE}
    },
};

void print_board(Square b[8][8]) {
    char syms[] = {' ', 'p', 'n', 'b', 'r', 'q', 'k'};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char s = syms[b[i][j].piece];
            putchar(b[i][j].color == BLACK ? toupper(s) : s);
        }
        putchar('\n');
    }
}

int main(void) {
    print_board(board);
    return 0;
}
