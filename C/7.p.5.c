#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int worth = 0;

    printf("Enter a fucking word: ");
    while((ch = toupper(getchar())) != '\n') {
        switch (ch) {
            case 'A': case 'E': case 'I': case 'L': case 'N':
            case 'O': case 'R': case 'S': case 'T': case 'U': worth += 1; break;
            case 'F': case 'H': case 'V': case 'W': case 'Y': worth += 4; break;
            case 'B': case 'C': case 'M': case 'P':           worth += 3; break;
            case 'D': case 'G':                               worth += 2; break;
            case 'J': case 'X': worth +=  8; break;
            case 'Q': case 'Z': worth += 10; break;
            case 'K':           worth +=  5; break;

            default:
                printf("What the fuckign shit is that? Fuck off!\n");
                return 1;
        }
    }
    printf("Scrabble value: %d\n", worth);
    return 0;
}
