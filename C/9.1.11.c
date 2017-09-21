#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_GRADES 1000

float compute_GPA(char grades[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        switch (toupper(grades[i])) {
            case 'A': sum += 4; break;
            case 'B': sum += 3; break;
            case 'C': sum += 2; break;
            case 'D': sum += 1; break;
            case 'F': break;
            default: printf("%c is not a fucking grade; fuck off!\n", grades[i]); exit(1);
        }
    }
    return sum / (float)n;
}

int main(void) {
    char grades[MAX_GRADES], ch;
    int n = 0;
    printf("Enter a bunch of fucking grades: ");
    while((ch = getchar()) != '\n') {
        if (ch == ' ') continue;
        if (n == MAX_GRADES) {
            printf("Jesus Fucking Christ, enough grades already! Using only the first %d\n", n);
            break;
        }
        grades[n++] = ch;
    }
    printf("The fucking GPA is %g\n", compute_GPA(grades, n));

    return 0;
}
