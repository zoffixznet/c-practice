#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c)-'a'+'A' : (c))

int main(void) {
    char s[100];
    int i;

    strcpy(s, "abcd");
    i = 0;
    // Fucking side effects, yo! Who are you trying to trick? I ain't getting fucking tricked!
    putchar(TOUPPER(s[++i])); // D

    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));  // 2
    putchar('\n');

    return 0;
}
