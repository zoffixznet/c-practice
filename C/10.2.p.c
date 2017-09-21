#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool flush, straight, four, flush, straight, three;
int pairs;

void read_cards(int num_in_rank[], int num_in_suit[]);
void analyze_hand(int num_in_rank[], int num_in_suit[]);
void print_result(void);

int main(void) {
    int num_in_rank[NUM_RANKS];
    int num_in_suit[NUM_RANKS];

    read_cards(num_in_rank, num_in_suit);
    analyze_hand(num_in_rank, num_in_suit);
    print_result();
    return 0;
}

void read_cards(int num_in_rank[], int num_in_suit[]) {
    int cards_read = 0, rank, suit;
    bool bad_card, cards_in_hand[NUM_RANKS][NUM_SUITS];

    printf("Ranks: 2 3 4 5 6 7 8 9 t j q k a\n");
    printf("Suits: c d h s\n");
    printf("Sample of a card: kc = King of Clubs; 6h = 6 of Hearts\n\n");

    for (int i = 0; i < NUM_RANKS; i++) {
        num_in_rank[i] = 0;
        for (int j = 0; j < NUM_SUITS; j++)
            cards_in_hand[i][j] = false;
    }
    for (int i = 0; i < NUM_SUITS; i++)
        num_in_suit[i] = 0;

    for (;;) {
        bad_card = false;
        rank = 0; // shut up whiny compiler
        suit = 0; // shut up whiny compiler

        printf("Enter a fucking card: ");
        switch (tolower(getchar())) {
            case '0': exit(EXIT_SUCCESS);
            case '2': rank = 0;  break;
            case '3': rank = 1;  break;
            case '4': rank = 2;  break;
            case '5': rank = 3;  break;
            case '6': rank = 4;  break;
            case '7': rank = 5;  break;
            case '8': rank = 6;  break;
            case '9': rank = 7;  break;
            case 't': rank = 8;  break;
            case 'j': rank = 9;  break;
            case 'q': rank = 10; break;
            case 'k': rank = 11; break;
            case 'a': rank = 12; break;
            default: bad_card = true;
        }

        switch (tolower(getchar())) {
            case 'c': suit = 0; break;
            case 'd': suit = 1; break;
            case 'h': suit = 2; break;
            case 's': suit = 3; break;
            default: bad_card = true;
        }

        char ch;
        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;

        if (bad_card) {
            printf("You gave me a bad fucking card. Try again, dumbass!\n");
        }
        else if (cards_in_hand[rank][suit]) {
            printf("You already entered that card. Try again, dumbass!\n");
        }
        else {
            cards_in_hand[rank][suit] = true;
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            if (++cards_read == NUM_CARDS)
                break;
        }
    }
}

void analyze_hand(int num_in_rank[], int num_in_suit[]) {
    flush    = false;
    straight = false;
    four     = false;
    flush    = false;
    straight = false;
    three    = false;
    pairs    = 0;

    // four-of-a-kind, three-of-a-kind, full house, and two or one pairs
    for (int i = 0; i < NUM_RANKS; i++) {
        if      (num_in_rank[i] == 4) four  = true;
        else if (num_in_rank[i] == 3) three = true;
        else if (num_in_rank[i] == 2) pairs++;
    }

    // flush
    for (int i = 0; i < NUM_SUITS; i++)
        if (num_in_suit[i] == NUM_CARDS)
            flush = true;

    // straight
    int num_consecutive = 0;
    int rank = 0;
    while (num_in_rank[rank] == 0) rank++;
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++, num_consecutive++);
    if (num_consecutive == NUM_CARDS) straight = true;
}

void print_result(void) {
    if (flush && straight)   { printf("A fucking straight flush. Good fucking job!\n"); }
    else if (four)           { printf("Four of a fucking kind\n"); }
    else if (pairs && three) { printf("Full fucking house, bitch\n"); }
    else if (flush)          { printf("A fucking flush\n"); }
    else if (straight)       { printf("A fucking straight\n"); }
    else if (three)          { printf("Three of a fucking kind\n"); }
    else if (pairs == 2)     { printf("Two fucking pairs\n"); }
    else if (pairs)          { printf("Just a fucking pair\n"); }
    else                     { printf("Just a \"high\" fucking card. What a fucking loser\n"); }
}
