#include <stdio.h>
#include <stdlib.h>

struct time {
    int h, m, s;
};

struct time split_time(long seconds);

int main(void) {
    long seconds;

    printf("Enter fucking seconds: ");
    if (scanf("%ld", &seconds) <= 0) exit(1);

    struct time time = split_time(seconds);
    printf("The time breaks down as: %d hours, %d minutes, and %d seconds\n",
      time.h, time.m, time.s);

    return 0;
}

struct time split_time(long seconds) {
    return (struct time){
        .h = seconds / 3600,
        .m = (seconds - (seconds/3600)*3600) / 60,
        .s = (seconds
          -  (seconds/3600)*3600
          -  ((seconds - (seconds/3600)*3600) / 60)*60)
    };
    // struct time time;
    // time.h = seconds / 3600;
    // time.m = (seconds - time.h*3600) / 60;
    // time.s = seconds - time.h*3600 - time.m*60;
    // return time;
}
