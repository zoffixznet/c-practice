#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1000

int main(void) {
    char ch;
    int a[MAX], *p = a;

    printf("Enter your fucking message:  ");
    while (p < a + MAX && (ch = tolower(getchar())) != '\n')
        if (ch >= 'a' && ch <= 'z')
            *p++ = ch;

    int *q = a-1;
    while (++q < --p)
        if (*q != *p) {
            printf("Not a fucking palindrome\n");
            exit(0);
        }

    printf("Fucking palindrome\n");

    return 0;
}
