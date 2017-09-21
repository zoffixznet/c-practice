#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LETTERS_NUM 26

void read_words(int letters[LETTERS_NUM]) {
    char ch;
    for (short i = 0; i < LETTERS_NUM; i++)
        letters[i] = 0;

    while ((ch = tolower(getchar())) != '\n')
        if (isalpha(ch))
            letters[ch - 'a']++;
}

bool equal_array(int a[LETTERS_NUM], int b[LETTERS_NUM]) {
    for (short i = 0; i < LETTERS_NUM; i++)
        if (a[i] != b[i]) return false;
    return true;
}

int main(void) {
    int letters1[26];
    int letters2[26];

    printf("Enter first fucking word: ");
    read_words(letters1);

    printf("Enter second fucking word: ");
    read_words(letters2);

    printf(equal_array(letters1, letters2)
        ? "The two are fucking anagrams\n"
        : "The words ain't no fucking anagrams\n");

    return 0;
}
