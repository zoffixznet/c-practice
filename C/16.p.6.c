#include <stdio.h>
#include <stdlib.h>

struct date {
    int day, month, year;
};

int compare_dates(struct date d1, struct date d2);

int main(void) {
    struct date d1, d2;
    printf("Enter first  date (mm/dd/yy): ");
    if (scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year) <= 0) exit(1);

    printf("Enter second date (mm/dd/yy): ");
    if (scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year) <= 0) exit(1);

    switch (compare_dates(d1, d2)) {
        case -1: printf("The first  date is fucking earlier\n"); break;
        case  0: printf("The fucking dates are the same\n");     break;
        case  1: printf("The second date is fucking earlier\n"); break;
    }

    return 0;
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
