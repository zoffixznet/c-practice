#include "readline.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int  number;
	char name[NAME_LEN+1];
	int  on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void) {
	char code;

	while(1) {
		printf("Enter operation mode: ");
		scanf(" %c", &code);
		while (getchar() != '\n')
			;
		switch (tolower(code)) {
			case 'i': insert(); break;
			case 's': search(); break;
			case 'u': update(); break;
			case 'p': print();  break;
			case 'q': exit(0);  break;
			default: printf("Only modes i, s, u, p, and q are valid\n");
		}
		putchar('\n');
	}
}

int find_part(int number) {
	for (int i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

void insert(void) {
    int part_number;
    if (num_parts == MAX_PARTS) {
        puts("Database is full; can't add more parts.");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0) {
        puts("Part already fucking exists");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_arts].name, NAME_LEN);
    printf("Enter fucking quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);

    num_parts++;
}
