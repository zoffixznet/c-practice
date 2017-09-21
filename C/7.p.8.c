#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int h, m, time;

    printf("Enter a 12-hour time [hh:mm AM/PM]: ");
    if (scanf("%d:%d", &h, &m) <= 0) return 1;
    while ((ch = getchar()) == ' ')
        ;
    if (toupper(ch) == 'P' && h != 12)
        h += 12;
    else if (h == 12)
        h = 0;
    if (toupper(getchar()) == 'M') // consume remaining M?\n
        getchar();
    time = h*60 + m;

    if (time < (8*60 + (21*60+43 - 24*60))/2  || time > 19*60 + (2*60+45)/2)
        printf("Closes departure time is 9:45pm, arriving at 11:58pm\n");
    else if (time < 8*60 + (60+43)/2)
        printf("Closes departure time is 9:43am, arriving at 11:52am\n");
    else //if (time < 9*60+43 + (60+43)/2)
        // ??? same strings printed? This program is fucked
        printf("Closes departure time is 9:43am, arriving at 11:52am\n");

    return 0;
}
