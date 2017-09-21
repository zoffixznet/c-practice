#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

unsigned short num;
unsigned long guesses;

void init_game(void) {
    guesses = 0;
    num = (rand() % 100) + 1;
    printf("\nA new number has been chosen\n");
}

bool guess(void) {
    guesses++;

    unsigned short guess;
    printf("Enter a guess: ");
    if (scanf("%hu", &guess) <= 0) {
        printf("I asked for a guess between 1 and 100 and you gave me trash. Fuck off!\n");
        exit(1);
    }
    getchar(); // clear '\n' from buffer

    if (guess == num) {
        printf("Holy fucking shit, you got it right! You won in %ld guesses!\n", guesses);
        return true;
    }
    else if (guess < num) {
        printf("Too fucking low\n");
        return false;
    }
    else {
        printf("Too fucking high\n");
        return false;
    }
}

int main(void) {
    srand((unsigned) time(NULL));
    printf("Welcome to the guestimator 4000! Guess the number between 1 and 100!\n");

    do {
        init_game();
        while ( ! guess())
            ;
        printf("\nPlay again? (Y/N): ");
    } while (tolower(getchar()) == 'y');
    printf("\nOh well, see ya later then!\n");
    return 0;
}
