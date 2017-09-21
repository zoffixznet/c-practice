#include <stdio.h>
#include <stdlib.h>

void reduce (int nu, int de, int *rn, int *rd);

int main(void) {
    int nu, de;

    printf("Enter a fucking fraction: ");
    if (scanf("%d/%d", &nu, &de) <= 0) exit(1);
    reduce(nu, de, &nu, &de);

    printf("Lowest fucking terms are: %d/%d\n", nu, de);
    return 0;
}

void reduce (int nu, int de, int *rn, int *rd) {
    int rem, m = nu, n = de;
    while (n != 0) {
        rem = m % n;
        m   = n;
        n   = rem;
    }

    *rn = nu / m;
    *rd = de / m;
}
