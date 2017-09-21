#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int word = 0;
    short worth[26] = {
        ['A'-'A'] = 1,
        ['E'-'A'] = 1,
        ['I'-'A'] = 1,
        ['L'-'A'] = 1,
        ['N'-'A'] = 1,
        ['O'-'A'] = 1,
        ['R'-'A'] = 1,
        ['S'-'A'] = 1,
        ['T'-'A'] = 1,
        ['U'-'A'] = 1,

        ['F'-'A'] = 4,
        ['H'-'A'] = 4,
        ['V'-'A'] = 4,
        ['W'-'A'] = 4,

        ['B'-'A'] = 3,
        ['C'-'A'] = 3,
        ['M'-'A'] = 3,
        ['P'-'A'] = 3,

        ['D'-'A'] = 2,
        ['G'-'A'] = 2,

        ['J'-'A'] = 8,
        ['X'-'A'] = 8,

        ['Q'-'A'] = 10,
        ['Z'-'A'] = 10,

        ['K'-'A'] = 5,
    };

    printf("Enter a fucking word: ");
    while((ch = toupper(getchar())) != '\n')
        word += worth[ch-'A'];
    printf("Scrabble value: %d\n", word);
    return 0;
}
