#include <stdio.h>

int main(void) {
    int area_code;
    printf("Enter the area code: ");
    scanf("%d", &area_code);

    switch (area_code) {
        default : printf("Area code not found\n"); break;
        case 404:
        case 678:
        case 770:
        case 470: printf("Atlanta\n");   break;
        case 706:
        case 762: printf("Columbus\n");  break;
        case 478: printf("Macon\n");     break;
        case 229: printf("Albany\n");    break;
        case 912: printf("Savannahy\n"); break;
    }
}
