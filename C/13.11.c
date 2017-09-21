#include <stdio.h>
#include <stdlib.h>

#define STR2(x) #x
#define STR(x) STR2(x)
#define MAX 1000

int str_cmp(char *s1, char *s2) {
    while (*s1++ == *s2++)
        if (*s1 == '\0')
            return 0;
    return *s1 - *s2;
}

int main (void) {
    char s1[MAX+1], s2[MAX+1];

    printf("Enter two fucking strings with no spaces in 'em: ");
    if (scanf("%" STR(MAX) "s", s1) <= 0) exit(1);
    if (scanf("%" STR(MAX) "s", s2) <= 0) exit(1);

    printf("The strings are %s\n",
        str_cmp(s1, s2) == 0 ? "the same" : "NOT the same");

    return 0;
}
