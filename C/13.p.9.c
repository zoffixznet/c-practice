#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000

int fucking_vowels(const char *s);
const char *read_line(char *s, int max);

int main(void) {
    char s[MAX_LEN];

    printf("Enter a fucking sentence: ");
    printf("Your shitty sentence contains %d vowels\n", fucking_vowels(read_line(s, MAX_LEN)));

    return 0;
}

int fucking_vowels(const char *s) {
    int count = 0;
    while (*s++)
        switch (toupper(*(s-1))) {
            case 'A': case 'E': case 'I': case 'O': case 'U': count++;
        }
    return count;
}

const char *read_line(char *s, int max) {
    char ch;
    char *pos = s;

    while (--max && (ch = getchar()) != '\n' && ch != EOF)
        *pos++ = ch;
    *pos = '\0';

    return s;
}
