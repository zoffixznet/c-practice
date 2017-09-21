#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    char *teens[] = {
        "ten",     "eleven",    "twelve",   "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"
    }, *tens[] = {
        "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "
    }, *ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    printf("Enter a two digit number, motherfucker: ");
    if (scanf("%d", &n) <= 0 || n < 10 || n > 99) {
        printf("I said TWO DIGITS! How fucking hard is that? Fuck you!\n");
        exit(1);
    }

    printf("You've entered ");
    if (10 <= n && n <= 19) {
        printf("%s\n", teens[n-10]);
        return 0;
    }
    printf("%s ", tens[n/10 - 2]);
    printf("%s\n", ones[n%10]);

    return 0;
}
