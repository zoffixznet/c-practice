#include <stdio.h>

#define MAX 1000

int read_line(char *str, int n);
void fuckitup(char *url);

int main(void) {
    char url[MAX];

    printf("Enter a fucking URL: ");
    read_line(url, MAX);

    fuckitup(url);
    printf("Fucking result is '%s'\n", url);

    return 0;
}

int read_line(char *str, int n) {
    int ch;
    int count = 0;
    n--;
    while ((ch = getchar()) != '\n')
        if (count < n)
            str[count++] = ch;
    str[count] = '\0';
    return count;
}

void fuckitup(char *url) {
    char *slash = NULL;

    while (*url)
        if (*url++ == '/')
            slash = url-1;

    if (slash)
        while (*slash)
            *slash++ = '\0';
}
