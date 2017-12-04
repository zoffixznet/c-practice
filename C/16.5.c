#include <stdio.h>
#include <stdlib.h>

struct date {
    int day, month, year;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void) {
    struct date d;
    printf("Enter a fucking date: yyyy/mm/dd: ");
    if (scanf("%4d/%2d/%2d", &d.year, &d.month, &d.day) <= 0) exit(1);
    printf("Day of the year is %d\n", day_of_year(d));

    switch (compare_dates(d, (struct date){.year = 2017, .month = 12, .day = 25})) {
        case -1: printf("Your date is earlier than Christmas\n"); break;
        case  0: printf("Your date is fucking Christmas\n"); break;
        case  1: printf("Your date is later than Christmas\n"); break;
    }

    return 0;
}

int day_of_year(struct date d) {
    const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count = d.day;
    for (int i = 0; i < d.month-1; i++)
        count += days[i];

    if (d.year % 4 == 0 && (d.year % 100 != 0 || d.year % 400 == 0))
      count++; // leap day

    return count;
}

int compare_dates(struct date d1, struct date d2) {
    return d1.year == d2.year
        ? d1.month == d2.month
            ? d1.day == d2.day
                ? 0
                : d1.day < d2.day ? -1 : 1
            : d1.month < d2.month ? -1 : 1
        : d1.year < d2.year ? -1 : 1;
}
