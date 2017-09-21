#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

short roll_dice(void) {
    short sum;
    sum = 1+rand()%6 + 1+rand()%6;
    printf("You rolled %hd\n", sum);
    return sum;
}

bool win(void) {
    printf("You win!\n");
    return true;
}

bool lose(void) {
    printf("You lose!\n");
    return false;
}

bool play_game(void) {
    short point, roll;

    switch (point = roll_dice()) {
        case 7: case 11:          return  win();
        case 2: case  3: case 12: return lose();
        default: for (;;) {
            roll = roll_dice();
            if (roll == point) return  win();
            if (roll == 7    ) return lose();
        }
    }
}

int main(void) {
    int wins = 0, games = 0;

    srand((unsigned) time(NULL));

    for (;;) {
        wins += play_game();
        games++;

        printf("\nPlay again? ");
        if (tolower(getchar()) != 'y') break;
        getchar(); // eat up the '\n' from user's entry above
        putchar('\n');
    }

    printf("You played %d games out of which you won %d and lost %d\n",
        games, wins, games-wins);

    return 0;
}
