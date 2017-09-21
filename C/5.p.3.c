#include <stdio.h>

int main(void) {
    float shares, price_per_share, trade, pay, pay_rival;

    printf("Enter number of shares: ");
    scanf("%f", &shares);
    printf("Enter price per share: ");
    scanf("%f", &price_per_share);
    trade = shares * price_per_share;

    if (trade < 2500.0f) {
        pay = 30.0f + trade*0.017f;
        if (pay < 39)
            pay = 39;
    }
    else if (trade < 6250.0f)
        pay = 56.0f + trade*0.0066f;
    else if (trade < 20000.0f)
        pay = 76.0f + trade*0.0034f;
    else if (trade < 50000.0f)
        pay = 100.0f + trade*0.0022f;
    else if (trade < 500000.0f)
        pay = 155.0f + trade*0.0011f;
    else
        pay = 255.0f + trade*0.0009f;

    printf("Commission:       $%.2f\n", pay);
    printf("Rival commission: $%.2f\n",
        33.0f + shares * (shares < 2000 ? 0.03f : 0.02f)
    );

    return 0;
}
