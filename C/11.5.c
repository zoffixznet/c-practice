#include <stdio.h>
#include <stdlib.h>

void split_time(long total_sec, int *h, int *m, int *s);

int main(void) {
    long secs;
    int h, m, s;

    printf("Enter a bunch of fucking seconds: ");
    if (scanf("%ld", &secs) <= 0) exit(1);

    split_time(secs, &h, &m, &s);
    printf("The fucking time is %.2d:%.2d:%.2d\n", h, m, s);

    return 0;
}

void split_time(long total_secs, int *h, int *m, int *s) {
    *h = total_secs/60/60;
    total_secs -= *h * 60 * 60;

    *m = total_secs/60;
    *s = total_secs - *m * 60;
}
