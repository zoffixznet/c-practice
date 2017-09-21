#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int h, m;
    bool pm = false;
    printf("Enter 24-hour time: ");
    scanf("%d:%d", &h, &m);

    if (h >= 12) {
        pm = true;
        if (h > 12) {
            h -= 12;
        }
    }
    else if (h == 0) {
        h = 12;
    }

    printf("Equivalent 12-hour time: %d:%.2d", h, m);
    printf(pm ? " PM\n" : " AM\n");

    return 0;
}
