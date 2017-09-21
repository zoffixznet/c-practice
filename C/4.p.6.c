#include <stdio.h>

int main(void)
{
    int i[12];
    printf("Enter the first 12 digits of EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &i[0], &i[1], &i[2], &i[3], &i[4],  &i[5],
        &i[6], &i[7], &i[8], &i[9], &i[10], &i[11]);

    printf("Check digit: %d\n",
      9 - (
        ( 3*(i[1]+i[3]+i[5]+i[7]+i[9]+i[11])
          + (i[0]+i[2]+i[4]+i[6]+i[8]+i[10])
        ) - 1
      ) % 10
    );

    return 0;
}
