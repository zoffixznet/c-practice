#include <stdio.h>

int main(void) {
    int num1, num2, den1, den2;
    printf("Enter first  fraction: "); scanf("%d /%d", &num1, &den1);
    printf("Enter second fraction: "); scanf("%d /%d", &num2, &den2);
    printf("Sum is: %d/%d\n", num1*den2 + num2*den1, den1*den2);
    return 0;
}
