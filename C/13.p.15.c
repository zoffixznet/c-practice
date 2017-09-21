#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN   1000

int stack_pointer, stack[MAX_LEN];
void push(int v);
int  pop(void);
bool is_empty(void);
bool is_full(void);

const char *read_line(char *s, int max);
int fuckRPN(const char *eval, long *result);

int main(void) {
    char expr[MAX_LEN];
    long result;
    int error;
    printf("Enter a fucking expression to eval: ");
    if ((error = fuckRPN(read_line(expr, MAX_LEN), &result)))
        puts(error == 1
            ? "The expression is too fucking complex. Fuck off!"
            : error == 2 ? "Not enough fucking operands for the operator. Fuck off!"
                : "Unknown error");
    else
        printf("The fucking result is %ld\n", result);

    return 0;
}

const char *read_line(char *s, int max) {
    char *pos = s, ch;
    while (--max && (ch = getchar()) != '\n' && ch != EOF)
        *pos++ = ch;
    *pos = '\0';
    return s;
}

int fuckRPN(const char *expr, long *result) {
    int temp;
    while (*expr) {
        if (*expr >= '0' && *expr <= '9')
            push(*expr - '0');
        else if (isspace(*expr)) {
            // nothing to do
        }
        else switch(*expr) {
            case '-': temp = pop(); push(pop() - temp); break;
            case '+': temp = pop(); push(pop() + temp); break;
            case '/': temp = pop(); push(pop() / temp); break;
            case '*': temp = pop(); push(pop() * temp); break;
            case '=': *result = pop(); return 0; break;
            default : return 1;
        }
        expr++;
    }
    return 2;
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

bool is_empty(void) { return (stack_pointer <= 0       ? true : false); }
bool is_full (void) { return (stack_pointer >= MAX_LEN ? true : false); }
