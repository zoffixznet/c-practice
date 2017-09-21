#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000

const char *read_line(char *s, int max);
double fucking_average_word_length(const char *s);

int main(void) {
    char str[MAX_LEN];

    printf("Enter a fucking sentence: ");
    printf("Average word length: %.1f\n", fucking_average_word_length(read_line(str, MAX_LEN)));

    return 0;
}

const char *read_line(char *s, int max) {
    char *pos = s, ch;
    while (--max && (ch = getchar()) != '\n' && ch != EOF)
        *pos++ = ch;
    *pos = '\0';
    return s;
}

double fucking_average_word_length(const char *s) {
    int n = *s ? 1 : 0;
    long total_len = 0;

    for (const char *p = s; *p; p++)
        if (! isspace(*p))
            total_len++;

    while (*++s)
        if (isspace(*s) && !isspace(*(s-1)))
            n++;

    if (n == 0) return 0.0;
    return (double)total_len / n;
}
