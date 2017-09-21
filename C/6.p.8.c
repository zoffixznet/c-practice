#include <stdio.h>

int main(void) {
    int day, week_day, days;

    printf("Enter the number of fucking days in the month: ");
    scanf("%d", &days);
    printf("Enter the fucking day of the week the fucking month starts on");
    printf(" (1=Sun, 7=Sat): ");
    scanf("%d", &week_day);

    for (int i = 1; i < week_day; i++)
        printf("   ");

    for (day = 1; day < days; day++) {
        printf("%2d ", day);
        if (week_day++ < 7) continue;
        week_day = 1;
        printf("\n");
    }
    printf("%d\n", day);

    return 0;
}
