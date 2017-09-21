#include <stdio.h>

long long calc_gcd(long long m, long long n);

int main(void) {
    char op;
    long long num1, num2, den1, den2, num_res, den_res, gcd;

    printf("Enter two fractions separated by a +, -, /, or * sign: ");
    if (scanf("%lld /%lld", &num1, &den1) <= 0) return 1;
    while ((op = getchar()) != '+' && op != '-' && op != '/' && op != '*')
        ;
    if (scanf("%lld /%lld", &num2, &den2) <= 0) return 1;

    switch (op) {
        case '+': num_res = num1*den2 + num2*den1; den_res = den1*den2; break;
        case '-': num_res = num1*den2 - num2*den1; den_res = den1*den2; break;
        case '*': num_res = num1*num2;             den_res = den1*den2; break;
        case '/': num_res = num1*den2;             den_res = den1*num2; break;
        default : printf("Never gonna get here\n"); return 1;
    }

    gcd = calc_gcd(num_res, den_res);
    num_res /= gcd;
    den_res /= gcd;

    printf("The result is: %lld/%lld\n", num_res, den_res);
}

long long calc_gcd(long long num, long long den) {
    long long rem;
    while (den != 0) {
        rem = num % den;
        num = den;
        den = rem;
    }
    return num;
}
