#include <stdio.h>

int main(void) {
    int week_day, days;

    printf("Enter the number of fucking days in the month: ");
    scanf("%d", &days);
    printf("Enter the fucking day of the week the fucking month starts on");
    printf(" (1=Sun, 7=Sat): ");
    scanf("%d", &week_day);

    for (int i = 1; i < week_day; i++)
        printf("   ");

    for (int day = 1; day <= days; day++) {
        printf("%3d", day);
        if ((week_day + day - 1) % 7 == 0 || day == days)
            printf("\n");
    }

    return 0;
}
