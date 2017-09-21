#include <stdio.h>

int main(void) {
    int h, m, time;

    printf("Enter a 24-hour time [hh:mm]: ");
    scanf("%d:%d", &h, &m);
    time = h*60 + m;

    if (time < (8*60 + (21*60+43 - 24*60))/2  || time > 19*60 + (2*60+45)/2)
        printf("Closes departure time is 9:45pm, arriving at 11:58pm\n");
    else if (time < 8*60 + (60+43)/2)
        printf("Closes departure time is 9:43am, arriving at 11:52am\n");
    else if (time < 9*60+43 + (60+43)/2)
        printf("Closes departure time is 9:43am, arriving at 11:52am\n");

    return 0;
}
