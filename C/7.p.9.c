#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    short h, m;

    printf("Enter a 12-hour fucking time [hh:mm AM/PM]: ");
    if (scanf("%hd:%hd", &h, &m) <= 0) return 1;
    while ((ch = getchar()) == ' ')
        ;
    if (toupper(ch) == 'P' && h != 12)
        h += 12;
    else if (h == 12)
        h = 0;
    if (toupper(getchar()) == 'M') // consume remaining M?\n
        getchar();

    printf("Fucking time is %hd:%.2hd\n", h, m);

    return 0;
}
