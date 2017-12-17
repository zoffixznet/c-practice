#include "line.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LINE_MAX 46

typedef struct word {
    char *word;
    struct word *next;
} Word;

Word *line = NULL;
int line_len  = 0;
int num_words = 0;

void clear_line(void) {
    while (line) {
        Word *to_del = line;
        line = line->next;
        free(to_del);
    }

    line_len  = 0;
    num_words = 0;
}

void add_word(const char *word) {
    Word *new_word = malloc(sizeof(*new_word));
    if (new_word == NULL) {
        printf("Could not allocate memory for a new word! Fuck off.\n");
        exit(1);
    }

    int len = strlen(word);
    line_len += len + 1; // +1 is for the space after the word
    new_word->word = malloc(len + 1);
    if (new_word->word == NULL) {
        printf("Could not allocate memory for a new word! Fuck off.\n");
        exit(1);
    }
    strcpy(new_word->word, word);

    new_word->next = NULL;
    if (line == NULL)
        line = new_word;
    else {
        Word *end = line;
        while (end->next != NULL)
            end = end->next;
        end->next = new_word;
    }

    num_words++;
}

int space_remaining(void) {
    return LINE_MAX - line_len;
}

void write_line(void) {
    int extra_spaces, spaces_to_insert;

    extra_spaces = space_remaining();
    while (line != NULL) {
        printf("%s", line->word);
        line = line->next;
        if (num_words > 1) {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (int j = 0; j <= spaces_to_insert; j++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
        }
        num_words--;
    }
    putchar('\n');
}

void flush_line(void) {
    while (line != NULL) {
        printf("%s", line->word);
        line = line->next;
        if (line != NULL)
            putchar(' ');
    }
    putchar('\n');
}
