#include <stdio.h>

int main(void)
{
    int i;
    printf("Enter a fucking number: ");
    scanf("%d", &i);
    printf("The reversal is: ");

    do {
        printf("%d", i % 10);
    } while (i /= 10);

    printf("\n\nNow, fuck off\n");
    return 0;
}
