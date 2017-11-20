#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "readline.h"

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
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter fucking quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);

    num_parts++;
}

void search(void) {
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Part name: M%s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else
      puts("Part not found.");
}

void update(void) {
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else
        puts("Part not found.");
}

void print(void) {
    printf("%7s      %-25s%11s\n", "Part number", "Part Name", "Quantity on Hand");
    for (int i = 0; i < num_parts; i++) {
        struct part p = inventory[i];
        printf("%7d      %-25s%11d\n", p.number, p.name, p.on_hand);
    }
}
