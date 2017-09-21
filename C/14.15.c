#include <stdio.h>

#define SPANISH

int main(void) {
    #ifdef ENGLISH
        puts("Insert Disk 1");
    #elif defined(FRENCH)
        puts("Inserez Le Disque 1");
    #elif defined(SPANISH)
        puts("Inserte El Disco 1");
    #else
        #error "You didn't provide the fucking language"
    #endif

    return 0;
}
