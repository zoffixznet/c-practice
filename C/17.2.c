#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dupe (char *s) {
    char *res = malloc(strlen(s)+1);
    if (res) strcpy(res, s);
    return res;
}

int main(void) {
    char *p = dupe("Fuck you fucking shit!");

    puts(p);
    *p = 'S';
    puts(p);

    return 1;
}
