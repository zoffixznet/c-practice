#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int nu, de;
} Rat;

void print_res(Rat r);
Rat read_rat(void);
Rat red_rat(Rat r);
Rat add_rat(Rat r1, Rat r2);
Rat sub_rat(Rat r1, Rat r2);
Rat mul_rat(Rat r1, Rat r2);
Rat div_rat(Rat r1, Rat r2);
int gcd(int a, int b);

int main(void) {
    Rat r1;
    printf("What op you wanna do [+ - * / _]: ");
    switch(getchar()) {
        case '+': r1 = read_rat(); print_res(add_rat(r1, read_rat())); break;
        case '-': r1 = read_rat(); print_res(sub_rat(r1, read_rat())); break;
        case '*': r1 = read_rat(); print_res(mul_rat(r1, read_rat())); break;
        case '/': r1 = read_rat(); print_res(div_rat(r1, read_rat())); break;
        case '_': print_res(red_rat(read_rat())); break;
        default: puts("Invalid op. Fuck off"); exit(1);
    }

    return 0;
}

void print_res(Rat r) {
    printf("The answer is %d/%d\n", r.nu, r.de);
}

Rat read_rat(void) {
    Rat r;
    printf("Enter a fucking rational number (d/d): ");
    if (scanf("%d/%d", &r.nu, &r.de) <= 0) exit(1);
    return r;
}

int gcd(int a, int b) {
    if (b) return gcd(b, a % b);
    else   return a;
}

Rat red_rat(Rat r) {
    int g = gcd(r.nu, r.de);
    if (g == 1)
        return r;
    else
        return (Rat){ .nu = r.nu/g, .de = r.de/g };
}

Rat add_rat(Rat r1, Rat r2) {
    return red_rat((Rat){
        .nu = r1.nu*r2.de + r2.nu*r1.de,
        .de = r1.de*r2.de
    });
}
Rat sub_rat(Rat r1, Rat r2) {
    return red_rat((Rat){
        .nu = r1.nu*r2.de - r2.nu*r1.de,
        .de = r1.de*r2.de
    });
}
Rat mul_rat(Rat r1, Rat r2) {
    return red_rat((Rat){ .nu = r1.nu*r2.nu, .de = r1.de*r2.de });
}
Rat div_rat(Rat r1, Rat r2) {
    return red_rat((Rat){ .nu = r1.nu*r2.de, .de = r1.de*r2.nu });
}
