#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
	int  number;
	char name[NAME_LEN+1];
	int  on_hand;
	struct part *next;
} *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void) {
	char code;

	while(1) {
		printf("Enter operation mode (i, s, u, p, or q): ");
		scanf(" %c", &code);
		while (getchar() != '\n')
			;
		switch (tolower(code)) {
			case 'i': insert(); break;
			case 's': search(); break;
			case 'u': update(); break;
			case 'p': print();  break;
			case 'q': exit(0);  break;
			default: printf("Invalid fucking operation mode\n");
		}
		putchar('\n');
	}
}

struct part *find_part(int number) {
	struct part *p;
	for (
		  p = inventory
		; p && p->number != number
		; p = p->next
	);
	return p;
}

void insert(void) {
	struct part *prev, *cur;
    int part_number;

    printf("Enter part number: ");
    if (scanf("%d", &part_number) <= 0) exit(1);

	for (
		  prev = NULL, cur = inventory
		; cur && cur->number < part_number
		; prev = cur, cur = cur->next
	);

    if (cur && cur->number == part_number) {
        puts("Part already fucking exists");
        return;
    }

	struct part *new_part = malloc(sizeof(struct part));
	if (!new_part) {
		puts("Could not allocate memory. Fuck off");
		exit(1);
	}
    new_part->number = part_number;
    printf("Enter part name: ");
    read_line(new_part->name, NAME_LEN);
    printf("Enter fucking quantity on hand: ");
    scanf("%d", &new_part->on_hand);

    if (cur)
		new_part->next = cur;

	if (prev)
		prev->next = new_part;
	else
		inventory = new_part;
}

void search(void) {
    int number;

    printf("Enter part number: ");
    scanf("%d", &number);
    struct part *part = find_part(number);
    if (part) {
        printf("Part name: %s\n", part->name);
        printf("Quantity on hand: %d\n", part->on_hand);
    }
    else
      	puts("Part not found.");
}

void update(void) {
    int number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    struct part *part = find_part(number);
    if (part) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        part->on_hand += change;
    }
    else
        puts("Part not found.");
}

void print(void) {
    printf("%7s      %-25s%11s\n", "Part number", "Part Name", "Quantity on Hand");
    for (struct part *p = inventory; p; p = p->next)
        printf("%7d      %-25s%11d\n", p->number, p->name, p->on_hand);
}
