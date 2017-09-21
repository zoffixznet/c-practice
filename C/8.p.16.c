#include <stdio.h>
#include <ctype.h>

int main(void) {
    int letters[26] = {0};
    char ch;

    printf("Enter first fucking word: ");
    while ((ch = tolower(getchar())) != '\n')
        if (isalpha(ch))
            letters[ch - 'a']++;

    printf("Enter second fucking word: ");
    while ((ch = tolower(getchar())) != '\n')
        if (isalpha(ch))
            letters[ch - 'a']--;

    for (short i = 0; i < 26; i++)
        if (letters[i] != 0) {
            printf("The words ain't no fucking anagrams\n");
            return 0;
        }

    printf("The two are fucking anagrams\n");
    return 0;
}
