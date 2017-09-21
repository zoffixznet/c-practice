#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv) {
    (void)argc;

    long long sum = 0;
    while (*++argv)
        sum += atoi(*argv);
    printf("The fucking sum is %lld\n", sum);

    return 0;
}
