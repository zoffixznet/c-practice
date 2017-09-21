#include <stdio.h>

#define MAX 100

int read_line(char *str, int n);
int count_spaces(const char *str);

int main(void) {
    char str[MAX];

    printf("Enter a fucking string: ");
    printf("You entered fucking %d-char string: %s\n",
        read_line(str, MAX), str);
    printf("It contains %d fucking spaces\n", count_spaces(str));
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

int count_spaces(const char *str) {
    int spaces = 0;
    for (; *str != '\0'; str++)
        if (*str == ' ')
            spaces++;
    return spaces;
}
