#include <stdio.h>

int main(void) {
    int grade;

    printf("Enter your fucking grade: ");
    scanf("%d", &grade);

    if (grade < 0 || grade > 100) {
        printf("You're full of shit. Fuck off!\n");
        exit(1);
    }

    switch (grade / 10) {
        case 10:
        case  9: printf("Fucking A!\n"); break;
        case  8: printf("Fucking B!\n"); break;
        case  7: printf("Fucking C!\n"); break;
        case  6: printf("Fucking D!\n"); break;
        default: printf("Fucking F!\n"); break;
    }

    return 0;
}
