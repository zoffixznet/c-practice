#include <stdio.h>

int main(void) {
    int ed, em, ey, d, m, y;

    printf("Enter a fucking date (mm/dd/yy): ");
    scanf("%d/%d/%d", &em, &ed, &ey);
    for (;;) {
        printf("Enter another fucking date (mm/dd/yy): ");
        scanf("%d/%d/%d", &m, &d, &y);
        if (!m && !d && !y) break;

        if (
               (y == ey && m == em && d < ed)
            || (y == ey && m < em)
            || (y <  ey)
        ) ey = y, em = m, ed = d;
    }

    printf("Earliest fucking date is %d/%d/%.2d\n", em, ed, ey);

    return 0;
}
