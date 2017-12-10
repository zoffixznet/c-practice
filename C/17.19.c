#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _STR2(x) #x
#define STR(x) _STR2(x)
#define MAX 100

void new_cmd()   { puts("Called new_cmd"  ); }
void open_cmd()  { puts("Called open_cmd" ); }
void save_cmd()  { puts("Called save_cmd" ); }
void print_cmd() { puts("Called print_cmd"); }
void exit_cmd()  { puts("Called exit_cmd" ); }

struct {
    char *cmd_name;
    void (*cmd_func)(void);
} file_cmd[] = {
    { "new",   new_cmd   },
    { "open",  open_cmd  },
    { "save",  save_cmd  },
    { "print", print_cmd },
    { "exit",  exit_cmd  }
};

void callit(char *cmd) {
    for (unsigned int i = 0; i < sizeof(file_cmd)/sizeof(file_cmd[0]); i++)
        if (strcmp(file_cmd[i].cmd_name, cmd) == 0) {
            file_cmd[i].cmd_func();
            return;
        }
    puts("Ain't no such fucking command");
}

int main(void) {
    while (1) {
        char cmd[MAX+1];
        printf("What command to run ('stop' to exit)? ");
        if (scanf("%" STR(MAX) "s", cmd) < 1) exit(1);
        if (strcmp(cmd, "stop") == 0) exit(0);
        callit(cmd);
    }

    return 0;
}
