#include <stdio.h>

int main(void) {
    float income;

    printf("Enter your income, bruh: ");
    scanf("%f", &income);

    printf("You owe: $%.2f\n",
          income <=  750.00f ?            income            *0.01f
        : income <= 2250.00f ?   7.50f + (income -  750.00f)*0.02f
        : income <= 3750.00f ?  37.50f + (income - 2250.00f)*0.03f
        : income <= 5250.00f ?  82.50f + (income - 3750.00f)*0.04f
        : income <= 7000.00f ? 142.50f + (income - 5250.00f)*0.05f
        :                      230.00f + (income - 7000.00f)*0.06f
    );

    return 0;
}
