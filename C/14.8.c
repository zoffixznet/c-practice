#include <stdio.h>

#define ___STR2(l) #l
#define ___STR1(l) ___STR2(l)
#define LINE_FILE "Line " ___STR1(__LINE__) " of file " __FILE__ "\n"

int main(void) {
    printf(LINE_FILE);

    return 0;
}
