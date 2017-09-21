#include <stdio.h>

#define MAX_LEN 1000

char *read_line(char *s, int max);
const char *fuckup_name(char *s);

int main(void) {
    char s[MAX_LEN];

    printf("Enter your fucking first and last names, assface: ");
    printf("Your shitty name is %s\n", fuckup_name(read_line(s, MAX_LEN)));

    return 0;
}

char *read_line(char *s, int max) {
    char *pos = s, ch;
    while (--max && (ch = getchar()) != '\n' && ch != EOF)
        *pos++ = ch;
    *pos = '\0';
    return s;
}
const char *fuckup_name(char *s) {
    char *head = s, *write_pos = s, initial;
    while (*s == ' ') s++; // skip preceeding whitespace
    initial = *s;

    while (*s && *s != ' ') s++; // skip rest of first name
    while (*s == ' ') s++; // skip whitespace between first and last names

    while (*s && *s != ' ') *write_pos++ = *s++; // write out last name and avoid trailing ws
    *write_pos++ = ',';
    *write_pos++ = ' ';
    *write_pos++ = initial;
    *write_pos++ = '.';
    *write_pos++ = '\0';

    return head;
}
