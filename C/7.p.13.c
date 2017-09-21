#include <stdio.h>

int main(void) {
    char  ch;
    int   n   = 0;
    long  len = 0;

    printf("Enter a fucking sentence: ");
    ch = getchar();
    while (ch != '\n') {
        while (ch == ' ')
            ch = getchar();
        if (ch != '\n')
            n++;
        while (ch != ' ' && ch != '\n') {
            len++;
            ch = getchar();
        }
    }
    if (n == 0) {
        printf("You didn't any words. Fuck off!\n");
        return 1;
    }

    printf("Average word length: %.1f\n", (float)len/n);

    return 0;
}
