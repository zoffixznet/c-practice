#include <stdio.h>

int main(void) {
    int n[4][4];
    int sum;
    printf("Enter numbers from 1 to 16 in any order:\n");
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &n[i][j]);

    printf("Row sums:");
    for (int i = 0; i < 4; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++)
            sum += n[i][j];
        printf(" %d", sum);
    }
    printf("\nColumn sums:");
    for (int j = 0; j < 4; j++) {
        sum = 0;
        for (int i = 0; i < 4; i++)
            sum += n[i][j];
        printf(" %d", sum);
    }
    printf("\nDiagonal sums: %d %d\n",
        n[0][0] + n[1][1] + n[2][2] + n[3][3],
        n[0][3] + n[1][2] + n[2][1] + n[3][0]
    );

    return 0;
}
