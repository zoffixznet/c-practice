#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int  number;
    char name[NAME_LEN+1];
    int  on_hand;
    double price;
};

int find_part(struct part inventory[], int num_parts, int number);
void insert(struct part inventory[], int *num_parts);
void search(struct part inventory[], int num_parts);
void update(struct part inventory[], int num_parts);
void print(struct part inventory[], int num_parts);
void reprice(struct part inventory[], int num_parts);
void partsort(struct part inventory[], int a[], int low, int high);
int partsort_split(struct part inventory[], int a[], int low, int high);

int main(void) {
	char code;
    int num_parts = 0;
    struct part inventory[MAX_PARTS];

	while(1) {
		printf("Enter operation mode: ");
		scanf(" %c", &code);
		while (getchar() != '\n')
			;
		switch (tolower(code)) {
			case 'i': insert (inventory, &num_parts); break;
			case 's': search (inventory,  num_parts); break;
			case 'u': update (inventory,  num_parts); break;
			case 'p': print  (inventory,  num_parts); break;
            case 'r': reprice(inventory,  num_parts); break;
			case 'q': exit(0);  break;
			default: printf("Only modes i, s, u, p, r, and q are valid\n");
		}
		putchar('\n');
	}
}

int find_part(struct part inventory[], int num_parts, int number) {
	for (int i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

void insert(struct part inventory[], int *num_parts) {
    int part_number;
    if (*num_parts == MAX_PARTS) {
        puts("Database is full; can't add more parts.");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(inventory, *num_parts, part_number) >= 0) {
        puts("Part already fucking exists");
        return;
    }

    inventory[*num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);
    printf("Enter fucking quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);
    printf("Enter fucking price: ");
    scanf("%lf", &inventory[*num_parts].price);

    (*num_parts)++;
}

void search(struct part inventory[], int num_parts) {
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);
    if (i >= 0) {
        printf("Part name: M%s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
        printf("Price: $%.2f\n", inventory[i].price);
    }
    else
      puts("Part not found.");
}

void update(struct part inventory[], int num_parts) {
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else
        puts("Part not found.");
}

void reprice(struct part inventory[], int num_parts) {
    int i, number;
    double new_price;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);
    if (i >= 0) {
        printf("Enter new fucking price: ");
        scanf("%lf", &new_price);
        inventory[i].price += new_price;
    }
    else
        puts("Part not found.");
}
void print(struct part inventory[], int num_parts) {
    printf("%7s      %-25s%11s%11s\n",
        "Part number", "Part Name", "Quantity on Hand", "Price");

    int indices[num_parts];
    for (int i = 0; i < num_parts; i++)
        indices[i] = i;

    partsort(inventory, indices, 0, num_parts-1);

    for (int i = 0; i < num_parts; i++) {
        struct part p = inventory[indices[i]];
        printf("%7d      %-25s%11d      $%.2f\n",
            p.number, p.name, p.on_hand, p.price);
    }
}

void partsort(struct part inventory[], int a[], int low, int high) {
    if (low >= high) return;

    int middle = partsort_split(inventory, a, low, high);
    partsort(inventory, a, low, middle - 1);
    partsort(inventory, a, middle + 1, high);
}

int partsort_split(struct part inventory[], int a[], int low, int high) {
    int el = a[low];
    while (1) {
        while (low < high && inventory[el].number <= inventory[a[high]].number)
            high--;
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && inventory[a[low]].number <= inventory[el].number)
            low++;
        if (low >= high) break;
        a[high--] = a[low];
    }

    a[high] = el;
    return high;
}
