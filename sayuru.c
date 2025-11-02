#include <stdio.h>

int MAX_FEEDBACKS = 10;
int MAX_FEEDBACK_LENGTH = 500;

void add_feedback(char feedbacks[][500], int *feedbackCount) {
    if (*feedbackCount < MAX_FEEDBACKS) {
        printf("Enter your feedback (max 500 characters):\n");
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
    char feedbacks[10][500];
    int feedbackCount = 0;
    int choice;

    while (1) {
        printf("\nRestaurant Feedback System\n");
        printf("1. Add Feedback\n");
        printf("2. Display Feedback\n");
        printf("3. Save Feedback to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_feedback(feedbacks, &feedbackCount);
                break;
            case 2:
                display_feedback(feedbacks, feedbackCount);
                break;
            case 3:
                save_feedback(feedbacks, feedbackCount, "feedback.txt");
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

        if (choice == 4) {
            break;
        }
    }

    return 0;
}

