#include <stdio.h>
#include <stdlib.h>

int sum (int (*f)(int), int start, int end) {
    if (start > end) {
        puts("Fuck off!");
        exit(1);
    }

    int sum = 0;;
    for (; start <= end; start++ )
        sum += (*f)(start);

    return sum;
}

int g(int i) {
    return i*i;
}

int main(void) {
    printf("Fucking sum is: %d\n", sum(g, 2, 10));
    return 0;
}
