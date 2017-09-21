#include <stdio.h>

#define SIZE ((int)(sizeof(a)/sizeof(a[1])))

int largest(int a[], int n);
int average(int a[], int n);
int num_positive(int a[], int n);

int main(void) {
    int a[] = {42, -10, 0, 20, 10, 55, -100};

    printf("Contents:");
    for (int i = 0; i < SIZE; i++)
        printf(" %d", a[i]);
    putchar('\n');
    printf("Largest: %d\n", largest(a, SIZE));
    printf("Average: %d\n", average(a, SIZE));
    printf("Number of positives: %d\n", num_positive(a, SIZE));
    return 0;
}

int largest(int a[], int n) {
    int largest = a[0];

    for (int i = 0; i < n; i++)
      if (a[i] > largest) largest = a[i];

    return largest;
}

int average(int a[], int n) {
    long long sum = 0;

    for (int i = 0; i < n; i++)
      sum += a[i];

    return sum / n;
}

int num_positive(int a[], int n) {
    int num = 0;

    for (int i = 0; i < n; i++)
        if (a[i] > 0) num++;

    return num;
}
