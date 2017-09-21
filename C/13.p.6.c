#include <stdio.h>
#include <strings.h>

#define NUM_PLANETS 9

int main(int argc, char **argv) {
    (void)argc;

    char *planets[NUM_PLANETS] = {
        "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn",
        "Uranus", "Neptune", "Pluto"
    };
    for (argv++; *argv != NULL; argv++) {
        char **p = planets;
        for (; p < planets + NUM_PLANETS; p++)
            if (strcasecmp(*p, *argv) == 0) // That's right bitch. strcasecmp! FUCK YOU!
                break;
        printf("%12s is %3s a fucking planet\n", *argv,
            p == planets + NUM_PLANETS ? "NOT" : "");
    }
    return 0;
}
