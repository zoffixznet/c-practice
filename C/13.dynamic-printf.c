#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char fucking_format[102], *fucker = fucking_format;
    printf("Enter your fucking format for the integer: ");
    if (scanf("%100s", fucking_format) <= 0) exit(1);

    while (*fucker)
        fucker++;
    *fucker++ = '\n';
    *fucker   = '\0';

    printf(fucking_format, 42);

    return 0;
}
