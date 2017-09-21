#include <stdio.h>

double tax (double income) {
    return
          income <=  750.00 ?           income           *0.01
        : income <= 2250.00 ?   7.50 + (income -  750.00)*0.02
        : income <= 3750.00 ?  37.50 + (income - 2250.00)*0.03
        : income <= 5250.00 ?  82.50 + (income - 3750.00)*0.04
        : income <= 7000.00 ? 142.50 + (income - 5250.00)*0.05
        :                     230.00 + (income - 7000.00)*0.06;
}

int main(void) {
    double income;

    printf("Enter your income, bruh: ");
    if (scanf("%lf", &income) <= 0) return 1;

    printf("You owe: $%.2f\n", tax(income));
    return 0;
}
