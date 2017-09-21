#include <stdio.h>

int main(void) {
    char ch, initial;

    printf("Enter your fucking first and last names, assface: ");
    while ((initial = getchar()) == ' ')
        ;
    while ((ch = getchar()) != ' ') // skip rest of first name
        ;
    while (ch == ' ') // skip spaces between names
        ch = getchar();

    printf("Your shitty name is ");
    putchar(ch);
    while ((ch = getchar()) != ' ' && ch != '\n')
        putchar(ch);
    printf(", %c.\n", initial);

    while (ch == ' ') // nom trailing whitespace
        ch = getchar();

    return 0;
}
