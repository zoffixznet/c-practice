#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void censor (char *str);
void read_line (char *str, int max);

int main (void) {
    char str[MAX_LEN];

    printf("Enter a fucking string: ");
    read_line(str, MAX_LEN);

    censor(str);
    printf("Censored version is: %s\n", str);
    return 0;
}

void censor (char *s) {
    for (;*s && *(s+1) && *(s+2); s++)
        if (strncmp(s, "foo", 3) == 0)
            strncpy(s, "xxx", 3);
}

void read_line (char *str, int max) {
    while (--max && (*str = getchar()) != '\n' && *str != EOF)
        str++;
    *str = '\0';
}
