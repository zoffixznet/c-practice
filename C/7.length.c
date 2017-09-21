#include <stdio.h>

int main(void) {
    unsigned int length;

    printf("Enter a fucking sentence: ");
    for (length = 0; getchar() != '\n'; length++)
        {}
    printf("The sentence if fucking %u chars long\n", length);

    return 0;
}
