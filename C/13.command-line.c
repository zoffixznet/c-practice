#include <stdio.h>

int main(int argc, char **argv) {
    printf("Fuck the argc! %d\nName of prog is '%s'\n", argc, *argv);
    for (argv++; *argv != NULL; argv++)
        printf("\t%s\n", *argv);
    return 0;
}
