#include <stdio.h>

int main(void) {
    float loan, rate, monthly;
    int n;
    printf("Enter amount of loan:   "); scanf("%f", &loan   );
    printf("Enter interest rate:    "); scanf("%f", &rate   );
    printf("Enter monthly payments: "); scanf("%f", &monthly);
    printf("How many payments are you making, assfuck? ");
    scanf("%d", &n);

    rate /= 1200;
    for (int i = 1; i <= n; i++) {
        printf("Balance remaining after %d payment: $%.2f\n", i,
            loan += loan*rate - monthly);
    }
}
