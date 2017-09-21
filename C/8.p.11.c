#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 15

int main(void) {
    char  ch;
    char  converted[MAX_SIZE];
    short digit_i = 0;

    printf("Enter a fucking phonenumber: ");
    while ((ch = toupper(getchar())) != '\n' && digit_i < MAX_SIZE) {
        switch(ch) {
            case 'A': case 'B': case 'C': ch = '2'; break;
            case 'D': case 'E': case 'F': ch = '3'; break;
            case 'G': case 'H': case 'I': ch = '4'; break;
            case 'J': case 'K': case 'L': ch = '5'; break;
            case 'M': case 'N': case 'O': ch = '6'; break;
            case 'P': case 'R': case 'S': ch = '7'; break;
            case 'T': case 'U': case 'V': ch = '8'; break;
            case 'W': case 'X': case 'Y': ch = '9'; break;
        }
        if ( (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') )
            converted[digit_i++] = ch;
    }
    if (ch != '\n') putchar('\n');
    printf("In fucking numeric form: ");
    for (short i = 0; i < digit_i; i++) {
        if (i == 1 || i == 4 || i == 7)
            putchar('-');
        printf("%c", converted[i]);
    }
    putchar('\n');

    return 0;
}
