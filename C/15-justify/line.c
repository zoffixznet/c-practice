#include "line.h"
#include <stdio.h>
#include <string.h>

<<<<<<< HEAD
#define LINE_MAX 100
=======
#define LINE_MAX 30
>>>>>>> x

char line[LINE_MAX+1];
int line_len  = 0;
int num_words = 0;

void clear_line(void) {
    line[0]   = '\0';
    line_len  = 0;
    num_words = 0;
}

void add_word(const char *word) {
    if (num_words > 0) {
        line[line_len  ] = ' ';
        line[line_len+1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void) {
    return LINE_MAX - line_len;
}

void write_line(void) {
    int extra_spaces, spaces_to_insert;

    extra_spaces = LINE_MAX - line_len;
    for (int i = 0; i < line_len; i++) {
        if (line[i] != ' ')
            putchar(line[i]);
        else {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (int j = 0; j <= spaces_to_insert; j++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n');
}

void flush_line(void) {
    if (line_len > 0)
        puts(line);
}
