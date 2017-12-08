#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *p;
    long long size = 1000000000;
    if (!(p = malloc(size))) {
        printf("Failed to allocate %lld bytes of memory. Fuck off\n", size);
        exit(1);
    }
    for (char *q = p; q - p < size; q++)
        if (*q == 0) *q = 1;

    *(p+size) = 0;
    puts(p);
}

// OUTPUT: More
