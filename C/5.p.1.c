#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);
    if (i < 0) i = -i;

    printf("The number has %d digits\n",
      i < 10 ? 1 : i < 100
          ? 2 : i < 1000
              ? 3 : i < 10000
                  ? 4 : 99999);

    return 0;
}
