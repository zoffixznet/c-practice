#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS   40
#define DIGIT_WIDTH  3
#define DIGIT_HEIGHT 3

char digits[MAX_DIGITS * DIGIT_WIDTH][DIGIT_HEIGHT];
int pos = 0;

void add_digit(int d);
void print_digits(void);
void add0(void);    void add1(void);    void add2(void);
void add3(void);    void add4(void);    void add5(void);
void add6(void);    void add7(void);    void add8(void);    void add9(void);

int main(void) {
    char ch;

    for (int i = 0; i < MAX_DIGITS*DIGIT_WIDTH; i++)
        for (int j = 0; j < DIGIT_HEIGHT; j++)
            digits[i][j] = ' ';

    printf("Enter some fucking digits: ");
    while ((ch = getchar()) != '\n')
        if (ch >= '0' && ch <= '9')
            add_digit(ch - '0');

    print_digits();

    return 0;
}

void print_digits(void) {
    for (int row = 0; row < DIGIT_HEIGHT; row++) {
        for (int col = 0; col < pos; col++)
            putchar(digits[col][row]);
        putchar('\n');
    }
    putchar('\n');
}

void add_digit(int d) {
    if (pos/DIGIT_WIDTH >= MAX_DIGITS) {
        printf("Cant' add any more fucking digits\n");
        exit(1);
    }

    switch (d) {
        case 0: add0(); break;  case 1: add1(); break;
        case 2: add2(); break;  case 3: add3(); break;
        case 4: add4(); break;  case 5: add5(); break;
        case 6: add6(); break;  case 7: add7(); break;
        case 8: add8(); break;  case 9: add9(); break;
        default:
            printf("I wanted a fucking digit (0-9) but you gave me %d\n", d);
            exit(1);
    }
}

void add0(void) {
    //  _
    // | |
    // |_|

    digits[pos+1][0] = '_';
    digits[pos  ][1] = '|';
    digits[pos+2][1] = '|';
    digits[pos  ][2] = '|';
    digits[pos+1][2] = '_';
    digits[pos+2][2] = '|';
    pos += DIGIT_WIDTH;
}

void add1(void) {
    //
    //   |
    //   |

    digits[pos+2][1] = '|';
    digits[pos+2][2] = '|';
    pos += DIGIT_WIDTH;
}

void add2(void) {
    //  _
    //  _|
    // |_

    digits[pos+1][0] = '_';
    digits[pos+1][1] = '_';
    digits[pos+2][1] = '|';
    digits[pos  ][2] = '|';
    digits[pos+1][2] = '_';
    pos += DIGIT_WIDTH;
}

void add3(void) {
    //  _
    //  _|
    //  _|

    digits[pos+1][0] = '_';
    digits[pos+1][1] = '_';
    digits[pos+2][1] = '|';
    digits[pos+1][2] = '_';
    digits[pos+2][2] = '|';
    pos += DIGIT_WIDTH;
}

void add4(void) {
    //
    // |_|
    //   |

    digits[pos  ][1] = '|';
    digits[pos+1][1] = '_';
    digits[pos+2][1] = '|';
    digits[pos+2][2] = '|';
    pos += DIGIT_WIDTH;
}

void add5(void) {
    //  _
    // |_
    //  _|

    digits[pos+1][0] = '_';
    digits[pos  ][1] = '|';
    digits[pos+1][1] = '_';
    digits[pos+1][2] = '_';
    digits[pos+2][2] = '|';
    pos += DIGIT_WIDTH;
}

void add6(void) {
    //  _
    // |_
    // |_|

    digits[pos+1][0] = '_';
    digits[pos  ][1] = '|';
    digits[pos+1][1] = '_';
    digits[pos  ][2] = '|';
    digits[pos+1][2] = '_';
    digits[pos+2][2] = '|';
    pos += DIGIT_WIDTH;
}

void add7(void) {
    //  _
    //   |
    //   |

    digits[pos+1][0] = '_';
    digits[pos+2][1] = '|';
    digits[pos+2][2] = '|';
    pos += DIGIT_WIDTH;
}

void add8(void) {
    //  _
    // |_|
    // |_|

    digits[pos+1][0] = '_';
    digits[pos  ][1] = '|';
    digits[pos+1][1] = '_';
    digits[pos+2][1] = '|';
    digits[pos  ][2] = '|';
    digits[pos+1][2] = '_';
    digits[pos+2][2] = '|';
    pos += DIGIT_WIDTH;
}

void add9(void) {
    //  _
    // |_|
    //  _|

    digits[pos+1][0] = '_';
    digits[pos  ][1] = '|';
    digits[pos+1][1] = '_';
    digits[pos+2][1] = '|';
    digits[pos+1][2] = '_';
    digits[pos+2][2] = '|';
    pos += DIGIT_WIDTH;
}
