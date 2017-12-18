#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 10

typedef struct word {
    char *word;
    struct word *next;
} Word;

void die(void);
Word *read_words(void);
void print_words(Word *words);
int sort_words(const void *a, const void *b);

int main(void) {
    print_words(read_words());
    return 1;
}

void die(void) {
    printf("Shit's fucked. Fuck off!\n");
    exit(1);
}

int sort_words(const void *a, const void *b) {
    char *sa, *sb;
    sa = ((Word *)a)->word;
    sb = ((Word *)b)->word;

    printf("Sorting `%s` <-> `%s`\n", sa, sb);
    return strcmp(sa, sb);
}

void print_words(Word *words) {
    if (! words) {
        printf("You didn't enter any fucking words, fucktard.\n");
        exit(1);
    }

    int word_count = 0;
    for (Word *c = words; c; word_count++, c = c->next);
    Word *sorted[word_count];

    int i = 0;
    for (Word *c = words; c; sorted[i++] = c, c = c->next);

    qsort(sorted, word_count, sizeof(Word *), sort_words);
    for (i = 0; i < word_count; i++) {
        if (i) putchar(' ');
        printf("%s", sorted[i]->word);
    }
    putchar('\n');
}

Word *read_words(void) {
    Word *words = NULL;
    while (1) {
        Word *word = malloc(sizeof(Word));
        if (! word) die();

        printf("Enter a fucking word (empty word to stop): ");
        size_t i = 0, len = 20;
        if (! (word->word = malloc(len))) die();
        while ((word->word[i] = getchar()) != '\n') {
            if (++i > len) {
                len *= 2;
                word->word = realloc(word->word, len);
                if (! word->word) die();
            }
        }
        if (i == 0) {
            free(word->word);
            free(word);
            return words;
        }
        word->word[i] = '\0';
        word->word = realloc(word->word, i+1);
        if (! word->word) die();
        word->next = words;
        words = word;
    }
}
