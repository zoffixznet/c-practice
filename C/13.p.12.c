#include <stdio.h>
#include <ctype.h>

#define MAX_WORDS 30
#define MAX_LEN   20

int main(void) {
    char sentence[MAX_WORDS][MAX_LEN+1], *letter = sentence[0], ch;
    int word = 0;

    printf("Enter a fucking sentence: ");
    while ((ch = getchar()) != EOF && ch != '.' && ch != '!' && ch != '?') {
        // We'll assume all words have just one fucking space between them
        if (isspace(ch)) {
            *letter = '\0';
            if (word++ >= MAX_WORDS) break;
            letter = sentence[word];
        }
        else
            *letter++ = ch;
    }
    *letter = '\0';
    if (ch != '!' && ch != '?') ch = '.';

    printf("Reversal sentence:");
    for (; word >= 0; word--)
        printf(" %s", sentence[word]);
    printf("%c\n", ch);

    return 0;
}
