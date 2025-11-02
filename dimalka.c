#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[100];
    int quantity;
};

void add_item(struct Item *items, int *count) {
    printf("Enter item name: ");
    scanf("%s", items[*count].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[*count].quantity);
    (*count)++;
}

void display_items(struct Item *items, int count) {
    printf("Item Name\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\n", items[i].name, items[i].quantity);
    }
}

void save_items(struct Item *items, int count, const char *orders) {
    FILE *fp;
    fp = fopen(orders, "w");
    if (fp == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d\n", items[i].name, items[i].quantity);
    }

    fclose(fp);
    printf("Items saved to %s successfully.\n", orders);
}

int main() {
    struct Item items[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\nRestaurant Oders List\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Save Items to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &count);
                break;
            case 2:
                display_items(items, count);
                break;
            case 3:
                save_items(items, count, "oders.txt");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


