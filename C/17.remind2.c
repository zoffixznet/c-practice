#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define STR2(x) #x
#define STR(x) STR2(x)
#define MAX_LEN    2000

int read_line(char *str, int n);

int main(void) {
    char *reminders[MAX_REMIND];
    char day_str[3], msg_str[MAX_LEN+1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            puts("No more fucking room");
            break;
        }

        printf("Enter day and reminder (or 0 to exit): ");
        if (scanf("%2d", &day) <= 0) {
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
            reminders[j] = reminders[j-1];

        if (!(reminders[i] = malloc(strlen(day_str) + strlen(msg_str) + 2)))
            exit(1);

        strcat(strcat(strcpy(reminders[i], day_str), " "), msg_str);

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
