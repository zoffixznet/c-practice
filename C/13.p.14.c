#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LEN 100

void read_line(char *s, int max);
bool fucking_anagrams(const char *s1, const char *s2);

int main(void) {
    char word1[MAX_LEN], word2[MAX_LEN];

    printf("Enter first fucking word: ");
    read_line(word1, MAX_LEN);
    printf("Enter second fucking word: ");
    read_line(word2, MAX_LEN);

    puts(fucking_anagrams(word1, word2)
        ? "The two are fucking anagrams"
        : "The words ain't no fucking anagrams");

    return 0;
}

void read_line(char *s, int max) {
    char ch;
    while (--max && (ch = getchar()) != '\n' && ch != EOF)
        *s++ = ch;
    *s = '\0';
}

bool fucking_anagrams(const char *s1, const char *s2) {
    int letters[26] = {0};
    while (*s1)
        if(isalpha(*s1))
            letters[tolower(*s1++) - 'a']++;
        else s1++;
    while (*s2)
        if(isalpha(*s2))
            letters[tolower(*s2++) - 'a']--;
        else s2++;

    for (int *p = letters; p < letters + 26; p++)
        if (*p != 0)
            return false;
    return true;
}
