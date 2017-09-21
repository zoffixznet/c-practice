#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MAX_LEN    200
#define DAY_STR_LEN 11  // 2 + 1 + 2 + 1 + 2 + 1 + 2 = 11
                        // "mm/dd hh:mm"

int read_line(char *str, int n);

int main(void) {
    char reminders[MAX_REMIND][MAX_LEN + DAY_STR_LEN + 1] = {{'\0'}};
    char msg_str[MAX_LEN+1], day_str[DAY_STR_LEN+1];
    int month, day, hour, minute, i, j, num_remind = 0;

    puts("Type 0 instead of date and reminder to quit");
    for (;;) {
        if (num_remind == MAX_REMIND) {
            puts("No more fucking room");
            break;
        }

        printf("Enter date and reminder (12/31 17:30 Foo): ");
        if (scanf("%d", &month) <= 0) {
            puts("Learn to follow fucking instructions");
            exit(1);
        }
        if (month == 0)
            break;

        if (scanf("/%d %d:%d", &day, &hour, &minute) <= 0) {
            puts("Learn to follow fucking instructions");
            exit(1);
        }
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            printf("Date %.2d/%.2d is fucking invalid!\n", month, day);
            continue;
        }
        if (hour < 0 || hour > 23 || minute < 0 || minute > 60) {
            printf("Time %.2d:%.2d is fucking invalid!\n", hour, minute);
            continue;
        }

        sprintf(day_str, "%2d/%2d %.2d:%.2d", month, day, hour, minute);
        read_line(msg_str, MAX_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    puts("\nDay Reminder");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

int read_line(char *str, int n) {
    int ch;
    int count = 0;
    n--;
    while ((ch = getchar()) != '\n')
        if (count < n)
            str[count++] = ch;
    str[count] = '\0';
    return count;
}
