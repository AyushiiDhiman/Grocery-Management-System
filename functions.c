#include <stdio.h>
#include <string.h>

struct Grocery {
    int id;
    char name[50];
    int qty;
    float price;
};

void addItem() {
    FILE *fp = fopen("functions.txt", "a");
    struct Grocery item;
    printf("Enter item ID: ");
    scanf("%d", &item.id);
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter quantity: ");
    scanf("%d", &item.qty);
    printf("Enter price: ");
    scanf("%f", &item.price);
    fprintf(fp, "%d %s %d %.2f\n", item.id, item.name, item.qty, item.price);
    fclose(fp);
    printf("Item added successfully.\n");
}

void displayItems() {
    FILE *fp = fopen("functions.txt", "r");
    struct Grocery item;
    printf("\nID\tName\tQty\tPrice\n");
    while (fscanf(fp, "%d %s %d %f", &item.id, item.name, &item.qty, &item.price) != EOF) {
        printf("%d\t%s\t%d\t%.2f\n", item.id, item.name, item.qty, item.price);
    }
    fclose(fp);
}

void updateItem() {
    struct Grocery item;
    int id, found = 0;
    FILE *fp = fopen("functions.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    while (fscanf(fp, "%d %s %d %f", &item.id, item.name, &item.qty, &item.price) != EOF) {
        if (item.id == id) {
            printf("Enter new name: ");
            scanf("%s", item.name);
            printf("Enter new quantity: ");
            scanf("%d", &item.qty);
            printf("Enter new price: ");
            scanf("%f", &item.price);
            found = 1;
        }
        fprintf(temp, "%d %s %d %.2f\n", item.id, item.name, item.qty, item.price);
    }
    fclose(fp);
    fclose(temp);
    remove("functions.txt");
    rename("temp.txt", "functions.txt");
    if (found) printf("Item updated successfully.\n");
    else printf("Item not found.\n");
}

void searchItem() {
    struct Grocery item;
    int id, found = 0;
    FILE *fp = fopen("functions.txt", "r");
    printf("Enter item ID to search: ");
    scanf("%d", &id);
    while (fscanf(fp, "%d %s %d %f", &item.id, item.name, &item.qty, &item.price) != EOF) {
        if (item.id == id) {
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", item.id, item.name, item.qty, item.price);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) printf("Item not found.\n");
}

void deleteItem() {
    struct Grocery item;
    int id, found = 0;
    FILE *fp = fopen("functions.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    while (fscanf(fp, "%d %s %d %f", &item.id, item.name, &item.qty, &item.price) != EOF) {
        if (item.id != id)
            fprintf(temp, "%d %s %d %.2f\n", item.id, item.name, item.qty, item.price);
        else
            found = 1;
    }
    fclose(fp);
    fclose(temp);
    remove("functions.txt");
    rename("temp.txt", "functions.txt");
    if (found) printf("Item deleted successfully.\n");
    else printf("Item not found.\n");
}

void groceryMenu() {
    int choice;
    while (1) {
        printf("\n--- Grocery Menu ---\n");
        printf("1. Add Item\n2. Display Items\n3. Update Item\n");
        printf("4. Search Item\n5. Delete Item\n6. Generate Bill\n7. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: updateItem(); break;
            case 4: searchItem(); break;
            case 5: deleteItem(); break;
            case 6: generateBill(); break;
            case 7: return;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}

void generateBill();  // Prototype to resolve external reference
