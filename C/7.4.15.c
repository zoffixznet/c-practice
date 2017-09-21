#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // typedef int8_t  Int8;
    // typedef int16_t Int16;
    // typedef int32_t Int32;
    // typedef int64_t Int64;

    typedef char  Int8;
    typedef short Int16;
    typedef int   Int32;
    typedef long  Int64;

    printf("short %zu\nint %zu\nlong %zu\nlong long %zu\n\n",
        8*sizeof(short), 8*sizeof(int), 8*sizeof(long), 8*sizeof(long long));

    printf("Int8 %zu\nInt16 %zu\nInt32 %zu\nInt64 %zu\n",
        8*sizeof(Int8), 8*sizeof(Int16), 8*sizeof(Int32), 8*sizeof(Int64));

    return 0;
}
