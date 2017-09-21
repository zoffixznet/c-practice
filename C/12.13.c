#include <stdio.h>

#define N 10

int main(void) {
    int a[N][N];

    int c = 0;
    for (int *p = a[0]; p < a[N]; p++) {
        *p = 42;
        c++;
    }
    printf("Processed %d entries; wanted %d\n", c, N*N);

    printf("The fucking array is:\n");
    for (int i = 0; i < N; i++) {
        int j = 0;
        for (; j < N-1; j++)
            printf("%d ", a[i][j]);
        printf("%d\n", a[i][j]);
    }

    return 0;
}
