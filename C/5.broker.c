#include <stdio.h>

int main(void) {
    float trade, pay;

    printf("Enter value of trade: ");
    scanf("%f", &trade);

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

    printf("Commission: $%.2f\n", pay);

    return 0;
}
