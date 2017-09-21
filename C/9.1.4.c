#include <stdio.h>

int day_of_year(int y, int m, int d); // fuck off with your backwards date formats

int main(void) {
    int y, m, d;
    printf("Enter a fucking date yyyy/mm/dd: ");
    if (scanf("%d/%d/%d", &y, &m, &d) <= 0) return 0;
    printf("Day of the year is fucking %d\n", day_of_year(y, m, d));
    return 0;
}

int day_of_year(int y, int m, int d) {
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < m; i++)
        d += months[i-1];
    if (m > 2 && y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
        d++;
    return d;
}
