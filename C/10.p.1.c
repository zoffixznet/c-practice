#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 100
#define INCOFUCKINGRECT printf("Incorrectly fucking nested! Fuck off!\n"); exit(EXIT_SUCCESS)

char contents[STACK_SIZE];
int top = 0;

void stack_overflow (void) { printf("Boom! Stack overflow,  bitch!\n"); exit(EXIT_FAILURE); }
void stack_underflow(void) { INCOFUCKINGRECT; }

void make_empty (void)  {        top = 0;           }
bool is_empty   (void)  { return top == 0;          }
bool is_full    (void)  { return top == STACK_SIZE; }
void push      (char i) { is_full()  ? stack_overflow()  : (contents[top++] = i); }
char pop        (void)  {
    if (is_empty()) stack_underflow();
    return contents[--top];
}

void check_shit(char wanted) {
    if (pop() != wanted) {
        INCOFUCKINGRECT;
    }
}

int main(void) {
    char ch;
    printf("Enter a bunch of fucking parentheses, brackets, and curlies: ");
    while ((ch = getchar()) != '\n')
        switch (ch) {
            case '[': case '(': case '{': push(ch); break;

            case ']': check_shit('['); break;
            case ')': check_shit('('); break;
            case '}': check_shit('{'); break;
        }

    if (! is_empty()) {
        INCOFUCKINGRECT;
    }

    printf("Correctly fucking nested\n");
    return 0;
}
