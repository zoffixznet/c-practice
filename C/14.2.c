#include <stdio.h>
#include <stdlib.h>

#define NELEMS(a) ((int)(sizeof(a) / sizeof(a[0])))
#define DUMP(n) printf(#n " has %d elements\n", NELEMS(n))

int main(void) {
    int i[42], *p = i;
    DUMP(i);
    DUMP(p);
    return 0;
}
