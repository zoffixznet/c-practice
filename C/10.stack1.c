#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void) { top = 0 }
bool is_empty(void)   { return top == 0          }
bool is_full (void)   { return top == STACK_SIZE }
void push(int i) { is_full()  ? stack_overflow()  : contents[top++] = i }
int  pop (void ) { is_empty() ? stack_underflow() : contents[--top]     }
