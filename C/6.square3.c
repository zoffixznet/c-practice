#include <stdio.h>

int main(void) {
    int i, n, odd, square;
    printf("Enter number of squares you wanna see:");
    scanf("%d", &n);

    for (square = 1, i = 1, odd = 3; i <= n; odd += 2) {
        printf("%10d%10d%10d\n", i, i*i, square);
        i++;
        square += odd;
    }

    return 0;
}
