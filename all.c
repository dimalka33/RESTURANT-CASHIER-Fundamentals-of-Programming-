#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[100];
    int quantity;
    float price;
};

int MAX_ITEMS = 100;
int MAX_FEEDBACKS = 10;
int MAX_FEEDBACK_LENGTH = 500;

void add_item(struct Item *items, int *count) {
    if (*count < MAX_ITEMS) {
        printf("Enter item name: ");
        scanf("%s", items[*count].name);
        printf("Enter item quantity: ");
        scanf("%d", &items[*count].quantity);
        printf("Enter item price: ");
        scanf("%f", &items[*count].price);
        (*count)++;
        printf("Item added successfully!\n");
    } else {
        printf("Item storage is full.\n");
    }
}

void display_items(struct Item *items, int count) {
    printf("\nRestaurant Orders List\n");
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

void generate_bill(struct Item *items, int count) {
    float total = 0;

    printf("\n********** ABC Restaurant Bill **********\n");
    printf("Item Name\tQuantity\tPrice\t\tTotal\n");
    for (int i = 0; i < count; i++) {
        float itemTotal = items[i].quantity * items[i].price;
        printf("%s\t\t%d\t\t%.2f\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price, itemTotal);
        total += itemTotal;
    }
    printf("\nTotal: %.2f\n", total);
}
void save_generate_bill(struct Item *items, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    fprintf(file, "\n********** ABC Restaurant Bill **********\n");
    fprintf(file, "Item Name\tQuantity\tPrice\t\tTotal\n");

    float total = 0;
    for (int i = 0; i < count; i++) {
        float itemTotal = items[i].quantity * items[i].price;
        fprintf(file, "%s\t\t%d\t\t%.2f\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price, itemTotal);
        total += itemTotal;
    }

    fprintf(file, "\nTotal: %.2f\n", total);

    fclose(file);
    printf("Bill saved to %s successfully.\n", filename);
}

void add_feedback(char feedbacks[][500], int *feedbackCount) {
    if (*feedbackCount < MAX_FEEDBACKS) {
        printf("\nEnter your feedback (max 500 characters):\n");
        getchar();
        fgets(feedbacks[*feedbackCount], MAX_FEEDBACK_LENGTH, stdin);
        (*feedbackCount)++;
        printf("Thank you for your feedback!\n");
    } else {
        printf("Feedback storage is full.\n");
    }
}

void display_feedback(char feedbacks[][500], int feedbackCount) {
    printf("\nCustomer Feedbacks:\n");
    for (int i = 0; i < feedbackCount; i++) {
        printf("%d. %s", i + 1, feedbacks[i]);
    }
}

void save_feedback(char feedbacks[][500], int feedbackCount, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    for (int i = 0; i < feedbackCount; i++) {
        fprintf(file, "%s", feedbacks[i]);
    }

    fclose(file);
    printf("Feedback saved to %s successfully.\n", filename);
}

int main() {
    struct Item items[100];
    char feedbacks[10][500];
    int itemCount = 0;
    int feedbackCount = 0;
    int choice;

    while (1) {
        printf("\nRestaurant Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Orders\n");
        printf("3. Save Orders to File\n");
        printf("4. Generate Bill\n");
	printf("5. Save Generate Bill to File\n");
        printf("6. Add Feedback\n");
        printf("7. Display Feedback\n");
        printf("8. Save Feedback to File\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &itemCount);
                break;
            case 2:
                display_items(items, itemCount);
                break;
            case 3:
                save_items(items, itemCount, "orders.txt");
                break;
            case 4:
                generate_bill(items, itemCount);
                break;
	    case 5:
                save_generate_bill(items, itemCount, "bills.txt");
                break;
            case 6:
                add_feedback(feedbacks, &feedbackCount);
                break;
            case 7:
                display_feedback(feedbacks, feedbackCount);
                break;
            case 8:
                save_feedback(feedbacks, feedbackCount, "feedback.txt");
                break;
            case 9:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
