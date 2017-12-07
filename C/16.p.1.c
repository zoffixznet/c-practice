#include <stdio.h>
#include <stdlib.h>

int main(void) {
    struct dialing_code {
        char *country;
        int code;
    };

    const struct dialing_code country_codes[] = {
        {"Argentina", 54}, {"Bangladesh", 880},
        {"Brazil", 55}, {"Burma (Myanmar)", 95},
        {"China", 86}, {"Colombia", 57},
        {"Congo", 243}, {"Egypt", 20},
        {"Ethiopia", 251}, {"France", 33},
        {"Germany", 49}, {"India", 91}
    };

    printf("Enter a fucking country code: ");

    int code;
    if (scanf("%d", &code) <= 0) exit(1);

    for (unsigned int i = 0; i < (sizeof(country_codes)/sizeof(country_codes[0])); i++)
        if (country_codes[i].code == code) {
            printf("The country for code %d is fucking %s\n", code, country_codes[i].country);
            exit(0);
        }

    printf("Don't know what the fuck code %d is for. Fuck off\n", code);
    return 1;
}
