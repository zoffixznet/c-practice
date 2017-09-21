#include <stdio.h>

#define MAX_SENTENCE_LENGTH 1000

int main(void) {
    char sentence[MAX_SENTENCE_LENGTH];
    char ch;
    short last_word_end;
    short i;

    printf("Enter a fucking sentence: ");
    i = 0;
    while (
        (ch = getchar()) != '.' && ch != '!' && ch != '?'
        && i < MAX_SENTENCE_LENGTH
    ) sentence[i++] = ch;
    if (ch != '!' && ch != '?')
        ch = '.';

    printf("Reversal sentence:");
    last_word_end = i--;
    for (short pos = i; pos >= 0; pos--) {
        if (sentence[pos] != ' ' && pos != 0 ) continue;

        putchar(' ');

        short word_pos = sentence[pos] == ' ' ? pos+1 : pos;
        for (; word_pos < last_word_end; word_pos++)
            putchar(sentence[word_pos]);
        last_word_end = pos;
    }
    printf("%c\n", ch);

    return 0;
}
