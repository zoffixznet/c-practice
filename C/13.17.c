#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

int read_line(char *str, int n);
bool test_ext(const char *file, const char *ext);

int main(void) {
    char file[MAX], ext[MAX];

    printf("Enter a fucking filename: ");
    read_line(file, MAX);
    printf("Enter a fucking extension: ");
    read_line(ext, MAX);

    puts(test_ext(file, ext) ? "MATCH!" : "NO FUCKING MATCH!");

    return 0;
}

int read_line(char *str, int n) {
    int ch;
    int count = 0;
    n--;
    while ((ch = getchar()) != '\n')
        if (count < n)
            str[count++] = ch;
    str[count] = '\0';
    return count;
}

bool test_ext(const char *file, const char *ext) {
    while (*file)
        if (*file++ == '.') {
            const char *f = file;
            const char *e = ext;
            while (tolower(*e++) == tolower(*f))
                if (*f++ == '\0')
                    return true;
        }
    return false;
}
