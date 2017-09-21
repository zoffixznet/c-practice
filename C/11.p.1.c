#include <stdio.h>
#include <stdlib.h>

void pay_amount(int a, int *b20, int *b10, int *b5, int *b1) {
    *b20 = a/20; a -= 20 * *b20;
    *b10 = a/10; a -= 10 * *b10;
    *b5  = a/5;  a -= 5  * *b5;
    *b1  = a;
}

int main(void) {
    int a;
    int b20, b10, b5, b1;

    printf("Enter the fucking amount you have to pay: ");
    if (scanf("%d", &a) <= 0) exit(1);

    pay_amount(a, &b20, &b10, &b5, &b1);
    printf("You need to fork over:\n");
    printf("$20: %d\n", b20);
    printf("$10: %d\n", b10);
    printf(" $5: %d\n", b5);
    printf(" $1: %d\n", b1);

    return 0;
}
