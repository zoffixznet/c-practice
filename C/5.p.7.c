#include <stdio.h>

void swap(int *a, int *b);

int main(void) {
    int n1, n2, n3, n4;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &n1, &n2, &n3, &n4);

    // split the 4 numbers in two groups and arrange smallest < largest in each:
    if (n2 < n1) swap(&n1, &n2);
    if (n4 < n3) swap(&n4, &n3);

    // check smallest of group 1 against smallest of group 2
    if (n3 < n1) swap(&n3, &n1);

    // check largest of group 1 against largest of group 2
    if (n2 > n4) swap(&n2, &n4);

    // with all the swaps done, n1 now contains smallest and n4 largest
    printf("Largest:\t%d\nSmallest:\t%d\n", n1, n4);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
