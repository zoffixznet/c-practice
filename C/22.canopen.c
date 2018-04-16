#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc != 2) {
        printf("Usage: %s some-filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("This file cannot be opened\n");
        exit(EXIT_FAILURE);
    }

    printf("Fucking 'ell! File `%s` can be read!\n", argv[1]);
    fclose(fp);
    exit(EXIT_SUCCESS);
}
