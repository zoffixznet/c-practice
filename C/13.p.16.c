#include <stdio.h>

#define MAX 1000

char *read_line (char *s, int max);
const char *reverse (char *message);


int main(void) {
    char str[MAX];

    printf("Enter your fucking message: ");
    printf("Fucking reversal is fucking: %s\n", reverse(read_line(str, MAX)));

    return 0;
}

char *read_line (char *s, int max) {
    char *p = s, ch;
    while (--max && (ch = getchar()) != '\n' && ch != EOF)
        *p++ = ch;
    *p = '\0';
    return s;
}

const char *reverse (char *message) {
    if (! *message) return message;

    char *end = message;
    while (*end) end++; end--;
    for (char *start = message; start < end; start++, end--) {
        char temp = *start;
        *start = *end;
        *end   =  temp;
    }

    return message;
}
