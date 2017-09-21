#include <stdio.h>

#define DUMP(v) printf(#v " = %d\n", v)
#define CHECK(x,y,n) ((x) >= 0 && (y) >= 0 && (x) <= ((n)-1) && (y) <= ((n)-1))

#define MEDIAN(x,y,z)  (                  \
       ((y) <= (x) && (x) <= (z))         \
    || ((z) <= (x) && (x) <= (y))         \
        ? (x)                             \
        :  ((x) <= (y) && (y) <= (z))     \
        || ((z) <= (y) && (y) <= (x))     \
            ? (y) : (z)                   \
    )

#define POLYNOMIAL(x) (((((3*(x) + 2)*(x) - 5)*(x) - 1)*(x) + 7)*(x) - 6)

int main(void) {
    DUMP(CHECK(1, 0, 10));
    DUMP(CHECK(10, 0, 10));

    DUMP(MEDIAN(1, 2, 3));
    DUMP(MEDIAN(3, 2, 1));
    DUMP(MEDIAN(2, 1, 3));
    DUMP(MEDIAN(2, 3, 1));
    DUMP(MEDIAN(3, 1, 2));
    DUMP(MEDIAN(3, 2, 1));

    DUMP(POLYNOMIAL(5));
    DUMP(POLYNOMIAL(10z));

    return 0;
}
