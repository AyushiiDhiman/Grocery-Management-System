#include <stdio.h>

void registerUser();
int login();
void groceryMenu();
void generateBill();

int main() {
    int choice;
    while (1) {
        printf("\n--- Grocery Management System ---\n");
        printf("1. Register\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (login()) {
                    groceryMenu();
                } else {
                    printf("Login failed.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
