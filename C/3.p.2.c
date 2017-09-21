#include <stdio.h>

int main(void) {
    int m, d, y, n;
    float p;
    printf("Enter item number: "); scanf("%d", &n);
    printf("Enter unit price:  "); scanf("%f", &p);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d /%d /%d", &m, &d, &y);

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$%7.2f\t\t%.2d/%.2d/%.4d\n", n, p, m, d, y);
    return 0;
}
