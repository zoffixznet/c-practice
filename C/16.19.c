#include <stdio.h>

struct pinball_machine {
    char name[40];
    int year;
    enum { EM, SS } type;
    int players;
};

int main(void) {
    struct pinball_machine meow = { "meows", 1992, SS, 42 };
    printf("%s, %d, %d, %d\n", meow.name, meow.year, meow.type, meow.players);
    return 0;
}
