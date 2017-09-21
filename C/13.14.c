#include <stdio.h>

int main (void) {
    char s[] = "Hsjodi", *p;
    for (p = s; *p; p++)
        --*p;
    puts(s); // perl6 -e '"Hsjodi".ords».&[-](1)».chr.join.say'
             // "Grinch"
             // Fuck you! You ain't gonna trick me!
    return 0;
}
