#include <stdio.h>

#define GENERIC_MAX(type) type type##_max(type x, type y) { return x > y ? x : y; }

// a) long long_max(long x, long y) { return x > y ? x : y; }

// b) 'cause it got a fucking space in its name, so we can't use it as function name, duh!

// c) Fucking typedef, motherfucker!
typedef unsigned long dong;
GENERIC_MAX(dong)

int main(void) {
    unsigned long x = 42, y = 70, z = 5;

    printf("%lu\n", dong_max(x, y));
    printf("%lu\n", dong_max(x, z));

    return 0;
}
