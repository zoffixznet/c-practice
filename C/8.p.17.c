#include <stdio.h>

int main(void) {

    short size = 5;
    printf("This program creates a magic square of fucking size\n");
    printf("Enter your fucking size. It must be an ODD number between 1 and 99: \n");
    if (scanf("%hd", &size) <= 0 || (size % 2) == 0 || size < 1 || size > 99) {
        printf("Follow the fucking instructions next time, fuckface\n");
        return 1;
    }

    int square[size][size];
    for (short i = 0; i < size; i++)
        for (short j = 0; j < size; j++)
            square[i][j] = -1;

    short x = size/2,  y = 0;
    for (int n = 1; n <= size*size; n++) {
        square[y][x] = n;
        x = (x + 1) % size;
        if (--y < 0) y = size - 1;

        if (square[y][x] != -1) {
            y = (y + 2) % size;
            if (--x < 0) x = size - 1;
        }
    }

    for (short i = 0; i < size; i++) {
        for (short j = 0; j < size; j++)
            printf("%10d", square[i][j]);
        putchar('\n');
    }

    return 0;
}
