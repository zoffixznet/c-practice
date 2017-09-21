#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_PLANETS 9

bool eqi(const char *str1, const char *str2);

int main(int argc, char **argv) {
    (void)argc;

    char *planets[NUM_PLANETS] = {
        "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn",
        "Uranus", "Neptune", "Pluto"
    };
    for (argv++; *argv != NULL; argv++) {
        char **p  = planets;
        for (; p < planets + NUM_PLANETS; p++)
            if (eqi(*argv, *p))
                break;
        printf("%12s is %3s a fucking planet\n", *argv,
            p == planets + NUM_PLANETS ? "NOT" : "");
    }

    return 0;
}

bool eqi(const char *str1, const char *str2) {
    while (tolower(*str1++) == tolower(*str2))
        if (*str2++ == '\0')
            return true;
    return false;
}
