#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 1000

char *read_line(char *s, int max);
bool is_palindrome(const char *s);

int main(void) {
    char s[MAX];

    printf("Enter your fucking message: ");

    puts(is_palindrome(read_line(s, MAX))
        ? "Fucking palindrome"
        : "Not a fucking palindrome");

    return 0;
}

char *read_line(char *s, int max) {
    char *pos = s;
    int ch;
    while (--max && (ch = getchar()) != '\n' && ch != EOF)
        *pos++ = ch;
    *pos = '\0';
    return s;
}

bool is_palindrome(const char *s) {
    if (! *s) return true;

    const char *end = s;
    while (*end) end++; end--;

    do {
        if (*s != *end) return false;
    } while (s++ < end--);
    return true;
}
