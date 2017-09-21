#include <stdio.h>

int main(void) {
    int d1, m1, y1, d2, m2, y2;
    printf("Enter first  date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m1, &d1, &y1);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m2, &d2, &y2);

    if (y1 == y2 && m1 == m2 && d1 == d2)
        printf("The fucking dates are the same\n");
    else if (
           (y1 == y2 && m1 == m2 && d1 < d2)
        || (y1 == y2 && m1 < m2)
        || (y1 <  y2)
    )    printf("The first  date is fucking earlier\n");
    else printf("The second date is fucking earlier\n");

    return 0;
}
