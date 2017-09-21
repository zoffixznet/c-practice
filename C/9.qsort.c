#include <stdio.h>

#define N 10

void quicksort (int a[], int low, int high);
int split (int a[], int low, int high);

int main(void) {
    int nums[N] = { 100, 45, 12, 534, -5,  512, 1, 5, 4, 7 };
    quicksort(nums, 0, N-1);

    printf("Result is:");
    for (int i = 0; i < N; i++)
        printf(" %d", nums[i]);
    putchar('\n');
    return 0;
}

void quicksort (int a[], int low, int high) {
    if (low >= high) return;

    int middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int split (int a[], int low, int high) {
    int part_elem = a[low];
    for (;;) {
        while (low < high && part_elem <= a[high])
            high--;
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= part_elem)
            low++;
        if (low >= high) break;
        a[high--] = a[low];
    }

    a[high] = part_elem;
    return high;
}
