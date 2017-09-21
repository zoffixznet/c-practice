#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void read_word(char *str, int max);

int main(void) {
    char last_word[MAX_LEN+1], start[MAX_LEN+1], end[MAX_LEN+1];

    read_word(last_word, MAX_LEN);
    strcpy(start, last_word);
    strcpy(end,   last_word);

    for (; strlen(last_word) != 4; read_word(last_word, MAX_LEN))
        if (strcmp(last_word, start) < 0)
            strcpy(start, last_word);
        else if (strcmp(last_word, end) >= 0)
            strcpy(end, last_word);

    printf("\nStarting word would be fucking '%s'\n", start);
    printf(  "Ending   word would be fucking '%s'\n", end);

    return 0;
}


void read_word(char *str, int max) {
    printf("Enter a fucking word (4-char word to stop): ");
    while (--max && (*str = getchar()) != '\n' && *str != EOF)
        str++;
    if (*str != '\n')
        str++;
     *str = '\0';
}
