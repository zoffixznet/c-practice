#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR2(x) #x
#define STR(x) STR2(x)
#define MAX 1000

void bail(void) {
    puts("Fuck off");
    exit(1);
}

char *concat(char *s1, char *s2);

int main(void) {
    char s1[MAX+1], s2[MAX+1];

    printf("Enter the first fucking string: ");
    if (scanf("%" STR(MAX) "s", s1) <= 0) bail();

    printf("Enter the second fucking string: ");
    if (scanf("%" STR(MAX) "s", s2) <= 0) bail();

    printf("The result is fucking `%s`\n", concat(s1, s2));
    return 1;
}

char *concat(char *s1, char *s2) {
    char *res;
    if (!(res = malloc(strlen(s1) + strlen(s2) + 1))) bail();

    strcpy(res, s1);
    strcat(res, s2);

    return res;
}

// OUTPUT: More
