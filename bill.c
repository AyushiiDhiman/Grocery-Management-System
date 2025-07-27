#include <stdio.h>
#include <string.h>

struct Grocery {
    int id;
    char name[50];
    int qty;
    float price;
};

void generateBill() {
    struct Grocery item;
    int id, qty, found = 0;
    float total = 0;

    FILE *inventory = fopen("functions.txt", "r");
    FILE *bill = fopen("bill.txt", "a");

    if (!inventory || !bill) {
        printf("Error opening files!\n");
        return;
    }

    printf("Enter item ID to purchase: ");
    scanf("%d", &id);
    printf("Enter quantity: ");
    scanf("%d", &qty);

    while (fscanf(inventory, "%d %s %d %f", &item.id, item.name, &item.qty, &item.price) != EOF) {
        if (item.id == id) {
            if (qty > item.qty) {
                printf("Not enough stock available.\n");
                fclose(inventory);
                fclose(bill);
                return;
            }

            float cost = qty * item.price;
            total += cost;

            fprintf(bill, "Item: %s | Qty: %d | Price: %.2f | Total: %.2f\n",
                    item.name, qty, item.price, cost);

            printf("\n--- BILL ---\n");
            printf("Item: %s\nQuantity: %d\nPrice: %.2f\nTotal: %.2f\n",
                   item.name, qty, item.price, cost);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Item not found in inventory.\n");

    fclose(inventory);
    fclose(bill);
}
