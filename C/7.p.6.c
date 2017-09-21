#include <stdio.h>

int main(void) {
    printf("char             %3zu\n", 8*sizeof(char)            );
    printf("short            %3zu\n", 8*sizeof(short)           );
    printf("int              %3zu\n", 8*sizeof(int)             );
    printf("long             %3zu\n", 8*sizeof(long)            );
    printf("long long        %3zu\n", 8*sizeof(long long)       );
    printf("float            %3zu\n", 8*sizeof(float)           );
    printf("double           %3zu\n", 8*sizeof(double)          );
    printf("long double      %3zu\n", 8*sizeof(long double)     );

    return 0;
}
