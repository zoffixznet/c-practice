#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
    bool in_hand[NUM_SUITS][NUM_RANKS] = {{false}};
    int num_cards, rank, suit;
    const char rank_code[] = {
        '2', '3', '4', '5', '6', '7', '8', '9',
        'T', 'J', 'Q', 'K', 'A'
    };
    const char suit_code[] = {'c', 'd', 'h', 's'};

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    if (scanf("%d", &num_cards) <= 0) return 1;
    if (num_cards <= 0 || num_cards > 52) {
        printf("Oh yeah? Fuck off then!\n");
        return 1;
    }

    printf("%d Your hand: ", RAND_MAX);
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if ( in_hand[suit][rank] ) continue;

        in_hand[suit][rank] = true;
        num_cards--;
        printf(" %c%c", rank_code[rank], suit_code[suit]);

    }
    putchar('\n');

    return 0;
}
