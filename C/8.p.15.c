#include <stdio.h>

#define MAX_MSG 80

int main(void) {
    char msg[MAX_MSG], ch;
    short pos = 0, shift;

    printf("Enter the message to be encrypted: ");
    while ((ch = getchar()) != '\n' && pos < MAX_MSG)
        msg[pos++] = ch;

    printf("Enter the ammount to shit (1-25): ");
    if (scanf("%hd", &shift) <= 0) return 1;
    if ( shift < 1 || shift > 25 ) {
        printf("What the fuck? Are you daft? I told you 1 through 25 only, you piece of shit!\n");
        return 1;
    }

    for (short i = 0; i < pos; i++) {
        ch = msg[i];
        if (ch >= 'a' && ch <= 'z')
            ch = 'a' + (ch - 'a' + shift) % 26;
        if (ch >= 'A' && ch <= 'Z')
            ch = 'A' + (ch - 'A' + shift) % 26;
        putchar(ch);
    }
    putchar('\n');

    return 0;
}
