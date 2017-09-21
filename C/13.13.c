#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

void build_index_url(const char *domain, char *index_url);
void read_line (char *str, int max);

int main (void) {
    char domain[MAX], index_url[MAX];

    printf("Enter a fucking domain name: ");
    read_line(domain, MAX);

    build_index_url(domain, index_url);
    printf("The index URL is fucking '%s'\n", index_url);

    return 0;
}

void build_index_url(const char *domain, char *index_url) {
    strcat(strcat(strcpy(index_url, "http://www."), domain), "/");
}

void read_line (char *str, int max) {
    while (--max && (*str = getchar()) != '\n' && *str != EOF)
        str++;
    *str = '\0';
}
