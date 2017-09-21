#include <stdio.h>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

int main(void) {
    int i = 42, j = 72;

    swap(&i, &j);
    printf("i is %d and j is %d\n", i, j);

    return 0;
}
