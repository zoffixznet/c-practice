#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MAX_LEN    200

int read_line(char *str, int n);

int main(void) {
    char reminders[MAX_REMIND][MAX_LEN+3] = {{'\0'}};
    char day_str[3], msg_str[MAX_LEN+1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            puts("No more fucking room");
            break;
        }

        printf("Enter day and reminder: ");
        if (scanf("%d", &day) <= 0) {
            puts("Learn to follow fucking instructions");
            exit(1);
        }
        if (day == 0)
            break;

        sprintf(day_str, "%2d", day);
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
