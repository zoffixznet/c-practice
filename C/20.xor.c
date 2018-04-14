#include <ctype.h>
#include <stdio.h>

#define KEY '&'

int main(void) {
    int c, enc;
    while ((c = getchar()) != EOF)
        if (isprint(c) && isprint(enc = c ^ KEY))
            putchar(enc);
        else
            putchar(c);
    return 0;
}
