#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
char *impl(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

#endif
