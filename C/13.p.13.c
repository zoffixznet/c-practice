#include <stdio.h>

#define MAX_MSG 80

const char *encrypt(char *msg, int shift);

int main(void) {
    char msg[MAX_MSG+1], ch;
    short pos = 0, shift;

    printf("Enter the message to be encrypted: ");
    while ((ch = getchar()) != '\n' && pos < MAX_MSG)
        msg[pos++] = ch;
    msg[pos] = '\0';

    printf("Enter the ammount to shit (1-25): ");
    if (scanf("%hd", &shift) <= 0) return 1;
    if ( shift < 1 || shift > 25 ) {
        printf("What the fuck? Are you daft? I told you 1 through 25 only, you piece of shit!\n");
        return 1;
    }

    printf("The fucking encrypted result is '%s'\n", encrypt(msg, shift));

    return 0;
}

const char *encrypt(char *msg, int shift) {
    for (char *pos = msg; *pos; pos++)
        if (*pos >= 'a' && *pos <= 'z')
            *pos = 'a' + (*pos - 'a' + shift) % 26;
        else if (*pos >= 'A' && *pos <= 'Z')
            *pos = 'A' + (*pos - 'A' + shift) % 26;
    return msg;
}
