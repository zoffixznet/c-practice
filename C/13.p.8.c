#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 1000
#define STR2(x) #x
#define STR(x) STR2(x)

int fucking_worth(const char *word);

int main(void) {
    char word[MAX_LEN+1];

    printf("Enter a fucking word: ");
    if (scanf("%" STR(MAX_LEN) "s", word) <= 0) {
        puts("FUCK YOU!");
        exit(1);
    }
    printf("Scrabble value: %d\n", fucking_worth(word));
    return 0;
}

int fucking_worth(const char *word) {
    int worth = 0;
    while(*word != '\0') {
        switch (toupper(*word++)) {
            case 'A': case 'E': case 'I': case 'L': case 'N':
            case 'O': case 'R': case 'S': case 'T': case 'U': worth += 1; break;
            case 'F': case 'H': case 'V': case 'W': case 'Y': worth += 4; break;
            case 'B': case 'C': case 'M': case 'P':           worth += 3; break;
            case 'D': case 'G': worth +=  2; break;
            case 'J': case 'X': worth +=  8; break;
            case 'Q': case 'Z': worth += 10; break;
            case 'K':           worth +=  5; break;

            default:
                printf("What the fuckign shit is that? Fuck off!\n");
                return 1;
        }
    }
    return worth;
}
