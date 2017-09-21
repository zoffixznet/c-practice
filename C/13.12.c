#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

void get_extension(const char *file, char *ext);
void read_line (char *str, int max);

int main (void) {
    char file[MAX], ext[MAX];

    printf("Enter a fucking filename: ");
    read_line(file, MAX);

    get_extension(file, ext);
    printf("The extension is fucking '%s'\n", ext);

    return 0;
}

void get_extension(const char *file, char *ext) {
    while (*file && *file != '.')
        file++;

    if (*file)
        strcpy(ext, ++file);
    else
        *ext = 0;
}

void read_line (char *str, int max) {
    while (--max && (*str = getchar()) != '\n' && *str != EOF)
        str++;
    *str = '\0';
}
