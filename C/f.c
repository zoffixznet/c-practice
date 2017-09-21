#include <stdio.h>

#define MVM_IS_32BIT_INT(i)     ((long long)i >= -2147483648LL && (long long)i <= 2147483647LL)
#define MVM_IS_32BIT_INT2(i)     ((long long)(i) >= -2147483648LL && (long long)(i) <= 2147483647LL)

int main(void) {
    int i, j;
    printf("%lld\n", MVM_IS_32BIT_INT(42 ? i : j));
    printf("%lld\n", MVM_IS_32BIT_INT2(42 ? i : j));
    return 0;
}
