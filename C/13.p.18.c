#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *months[] = {
        "January", "February", "March",     "April",   "May",      "June",
        "July",    "August",   "September", "October", "November", "December"
    };
    int month, day, year;

    printf("Enter a fucking date (yyyy/mm/dd): ");
    if (scanf("%4d/%2d/%2d", &year, &month, &day) <= 0
        || month < 1 || month > 12
    ) {
        puts("You entered some fucking bullshit. Fuck off!");
        exit(1);
    }

    printf("The fucking date is %s %d, %d\n", months[month-1], day, year);

    return 0;
}
