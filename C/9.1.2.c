#include <stdio.h>
#include <stdbool.h>

bool check(int x, int y, int n) {
    return x >= 0 && x <= n-1 && y >= 0 && y <= n-1;
}

int main(void) {
    int x, y, n;
    printf("Enter x, y, and n: ");
    if (scanf("%d %d %d", &x, &y, &n) <= 0) return 1;
    printf("Check is %d\n", check(x, y, n));
    return 0;
}
