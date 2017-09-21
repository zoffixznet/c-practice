#include <stdio.h>

int main(void) {
    char op = '+';
    long double result = 0, num;

    printf("Enter some fucking expression. NO FUCKIGN SPACES!!: ");
    for (;;) {
        if (scanf("%Lf", &num) <= 0) {
            printf("Lose some weight, Fuckface McFatFingers\n");
            return 1;
        }
        switch (op) {
            case '+' : result += num; break;
            case '-' : result -= num; break;
            case '*' : result *= num; break;
            case '/' : result /= num; break;
        }
        if ((op = getchar()) == '\n') {
            printf("The result is fucking %Lg\n", result);
            return 0;
        }
    }
}
