#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int vowels = 0;

    printf("Enter a fucking sentence: ");
    while ((ch = toupper(getchar())) != '\n')
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            vowels++;
    printf("Your shitty sentence contains %d vowels\n", vowels);

    return 0;
}
