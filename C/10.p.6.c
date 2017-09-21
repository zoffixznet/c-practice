#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 1000

int stack_pointer, stack[STACK_SIZE];

void welcome(void);
void push(int v);
int  pop(void);
bool is_empty(void);
bool is_full(void);

int main(void) {
    char ch;
    int temp;

    welcome();
    for (;;) {
        if (scanf(" %c", &ch) <= 0) exit(1);

        if (ch >= '0' && ch <= '9')
            push(ch - '0');
        else switch(ch) {
            case '-': temp = pop(); push(pop() - temp); break;
            case '+': temp = pop(); push(pop() + temp); break;
            case '/': temp = pop(); push(pop() / temp); break;
            case '*': temp = pop(); push(pop() * temp); break;
            case '=': printf("Fucking value of the expression is %d\n", pop());
                      welcome();
                      break;
            default: exit(0);
        }
    }

    return 0;
}

void welcome(void) {
    while (! is_empty()) pop();
    printf("Enter your fucking RPN expression: ");
}

void push(int v) {
    if (is_full()) {
        printf("The expression is too fucking complex. Fuck off!\n");
        exit(1);
    }
    stack[stack_pointer++] = v;
}

int pop(void) {
    if (is_empty()) {
        printf("Not enough fucking operands for the operator. Fuck off!\n");
        exit(1);
    }
    return stack[--stack_pointer];
}

bool is_empty(void) { return (stack_pointer <= 0          ? true : false); }
bool is_full (void) { return (stack_pointer >= STACK_SIZE ? true : false); }
