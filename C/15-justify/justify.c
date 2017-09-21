#include "word.h"
#include "line.h"
#include <string.h>

#define WORD_MAX 20

int main(void) {
    char word[WORD_MAX+2];
    int word_len;

    clear_line();
    for (;;) {
        read_word(word, WORD_MAX+1);

        word_len = strlen(word);
        if (word_len == 0) {
            flush_line();
            return 0;
        }
        if (word_len > WORD_MAX)
            word[WORD_MAX] = '*';
        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }

        add_word(word);
    }
}
