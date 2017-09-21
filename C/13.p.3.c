#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
    bool in_hand[NUM_SUITS][NUM_RANKS] = {{false}};
    int num_cards, rank, suit;
    const char *rank_code[] = {
        "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Jack", "Queen", "King", "Ace"
    };
    const char *suit_code[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    if (scanf("%d", &num_cards) <= 0 || num_cards <= 0 || num_cards > 52) {
        printf("Oh yeah? Fuck off then!\n");
        exit(1);
    }

    puts("Your hand:");
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if ( in_hand[suit][rank] ) continue;

        in_hand[suit][rank] = true;
        num_cards--;
        printf("%5s of Fucking %s\n", rank_code[rank], suit_code[suit]);

    }
    putchar('\n');

    return 0;
}
