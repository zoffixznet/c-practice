#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 1000

void selection_sort(int nums[], int nums_size) {
    if (nums_size == 0) return;

    int max = nums_size - 1;
    for (int i = 0; i < nums_size - 1; i++)
        if (nums[i] > nums[max])
            max = i;

    if (max != nums_size - 1) {
        int temp = nums[nums_size-1];
        nums[nums_size-1] = nums[max];
        nums[max] = temp;
    }

    selection_sort(nums, nums_size - 1);
}

int main(void) {
    int num, nums_size = 0, nums[MAX_NUMS];
    printf("Enter a bunch of fucking integer numbers; type 0 when you're done: ");
    for (;;) {
        if (scanf("%d", &num) <= 0) {
            printf("You didn't type the right shit! Go fuck yourself!\n");
            exit(1);
        }
        if (num == 0 || nums_size >= MAX_NUMS) break;
        nums[nums_size++] = num;
    }

    selection_sort(nums, nums_size);

    printf("Here are your fucking numbers sorted, fuckface:");
    for (int i = 0; i < nums_size; i++)
        printf(" %d", nums[i]);
    putchar('\n');

    return 0;
}
