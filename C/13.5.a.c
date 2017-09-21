#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 1000

void capitalize (char *str);
void read_line (char *str, int max);

int main (void) {
    char str[MAX_LEN];

    printf("Enter a fucking string: ");
    read_line(str, MAX_LEN);

    capitalize(str);
    printf("Capitalized version is: %s\n", str);
    return 0;
}

void capitalize (char *s) {
    for (;*s; s++)
        *s = toupper(*s);
}

void read_line (char *str, int max) {
    while (--max && (*str = getchar()) != '\n' && *str != EOF)
        str++;
    *str = '\0';
}
