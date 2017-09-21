#include <stdio.h>

#define MAX 100

int read_line(char *str, int n);

int main(void) {
    char str[MAX];

    printf("Enter a fucking string: ");
    printf("You entered fucking %d-char string: %s\n",
        read_line(str, MAX), str);
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

// void read_line (char *str, int max) {
//     while (--max && (*str = getchar()) != '\n' && *str != EOF)
//         str++;
//     *str = '\0';
// }
