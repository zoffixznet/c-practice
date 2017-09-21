#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int read_line(char *str, int n);

int main(void) {
    char str[MAX];
    printf("Enter a fucking string: ");
    read_line(str, MAX);
    printf("You entered '%s'\n", str);
    return 0;
}

int read_line(char *str, int n) {
    int ch;
    int count = 0;

    // skip leading whitespace
    while (isspace(ch = getchar()))
        ;
    ungetc(ch, stdin);

    while ((ch = getchar()) != EOF && ! isspace(ch))
        if (count < n-2)
            str[count++] = ch;
        else break;
    if (ch == '\n')
        str[count++] = '\n';

    str[count] = '\0';
    return count;
}
