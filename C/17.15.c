#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main(void) {
    printf("Answer: %d\n", f1(f2));
    // It fucking brute-forces a solution to a quadaratic equation
    // Answer is fucking 3
    return 0;
}

int f1(int (*f)(int)) {
    int n = 0;

    while ((*f)(n)) n++;
    return n;
}

int f2(int i) {
    return i*i + i - 12;
}
