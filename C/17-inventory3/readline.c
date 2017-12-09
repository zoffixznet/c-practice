#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n) {
    int ch;
    while (isspace(ch = getchar()))
        ;

    int count = 0;
    while (ch != '\n' && ch != EOF) {
        if (count < n)
            str[count++] = ch;
        ch = getchar();
    }
    str[count] = '\0';
    return count;
}
