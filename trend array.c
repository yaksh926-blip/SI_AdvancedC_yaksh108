#include <stdio.h>
int main() {
    int id[10]       = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int stock[10]    = {5, 10, 15, 12, 14, 16, 13, 12, 10, 11};
    double mrp[10]   = {2999.00, 3499.00, 1999.00, 2499.00, 3999.00, 
                        1799.00, 9999.00, 14999.00, 2799.00, 1599.00};
    double discount[10] = {10.0, 15.0, 5.0, 20.0, 10.0, 
                           8.0, 25.0, 15.0, 12.0, 5.0};
    char brand[10][20] = {
        "Nike", "Adidas", "Levi's", "Puma", "Zara", 
        "H&M", "Gucci", "LouisVuitton", "UnderArmour", "Uniqlo"
    };
    int choice, i;
    do {
        printf("\n====WELCOME TO TRENDS===");
        printf("\n======MENU======\n");
        printf("1: View Inventory Stock\n");
        printf("2: Purchase Items\n");
        printf("3: Checkout & Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        while (choice < 1 || choice > 3) {
            printf("\nInvalid Choice, please try again\n");
            printf("Enter Your Choice: ");
            scanf("%d", &choice);
        }
        if (choice == 1) {
            printf("\nProduct_ID\tBrand\t\tMRP\t\tDiscount%%\tAvailable_Qty\n");
            printf("-----------------------------------------------------------------------\n");
            for (i = 0; i < 10; i++) {
                printf("%d\t\t%-12s\tRs.%.2f\t\t%.1f%%\t\t%d\n", 
                       id[i], brand[i], mrp[i], discount[i], stock[i]);
            }
        }
        else if (choice == 2) {
            int PI, quantity, found_index = -1;
            printf("Enter the product ID: ");
            scanf("%d", &PI);
            for (i = 0; i < 10; i++) {
                if (PI == id[i]) {
                    found_index = i;
                    break;
                }
            }
            if (found_index != -1) {
                double final_price = mrp[found_index] - (mrp[found_index] * (discount[found_index] / 100.0));
                printf("Product Found! Brand: %s | MRP: Rs.%.2f | Discount: %.1f%% | Final Price: Rs.%.2f\n", 
                       brand[found_index], mrp[found_index], discount[found_index], final_price);
                printf("Available Stock: %d\n", stock[found_index]);
                printf("Enter the Quantity of product: ");
                scanf("%d", &quantity);
                if (quantity > 0 && quantity <= stock[found_index]) {
                    printf("Quantity is Available\n");
                    stock[found_index] -= quantity;
                    printf("Remaining stock for ID %d: %d\n", id[found_index], stock[found_index]);
                    double total_bill = final_price * quantity;
                    printf("Total cost for this item: Rs.%.2f\n", total_bill);
                } else {
                    printf("Quantity is not available or invalid!\n");
                }
            } else {
                printf("Enter a valid product ID (Product Not Found)\n");
            }
        }
        else if (choice == 3) {
            printf("\nThank you for shopping at Trends. Have a nice day!\n");
        }
    } while (choice != 3);
    return 0;
}