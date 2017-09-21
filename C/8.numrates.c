#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))

int main(void) {
    int years;
    double value[5], rate, initial_balance;

    printf("Enter interest rate: ");
    if (scanf("%lf", &rate) <= 0) return 1;
    printf("Enter number of years: ");
    if (scanf("%d", &years) <= 0) return 1;
    printf("Enter initial balance: ");
    if (scanf("%lf", &initial_balance) <= 0) return 1;

    printf("\nYears     ");
    for (int i = 0; i < NUM_RATES; i++) {
        printf("%g%%          ", rate+i);
        value[i] = initial_balance;
    }

    for (int year = 1; year <= years; year++) {
        printf("\n%5d    ", year);
        for (int i = 0; i < NUM_RATES; i++)
            printf(" $%10.2f", value[i] += (rate+i)*value[i] / 100.0);
    }
    putchar('\n');

    return 0;
}
