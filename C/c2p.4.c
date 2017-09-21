#include <stdio.h>

int main(void) {
    float amount;
    printf("Enter teh amount, bruh: "); scanf("%f", &amount);
    printf("With the taxes that's $%.2f\n", 1.05f * amount);
    return 0;
}
