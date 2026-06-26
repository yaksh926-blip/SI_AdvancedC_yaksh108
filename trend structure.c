#include <stdio.h>
struct Product {
    int id;
    int stock;
    double mrp;
    double discount; 
    char brand[20]; 
};
int main() {
    struct Product inventory[10] = {
        {101, 5,  2999.00,  10.0, "Nike"},         
        {102, 10, 3499.00, 15.0, "Adidas"},        
        {103, 15, 1999.00,  5.0,  "Levi's"},      
        {104, 12, 2499.00, 20.0, "Puma"},         
        {105, 14, 3999.00, 10.0, "Zara"},         
        {106, 16, 1799.00,  8.0, "H&M"},           
        {107, 13, 9999.00, 25.0, "Gucci"},         
        {108, 12, 14999.00, 15.0, "LouisVuitton"}, 
        {109, 10, 2799.00, 12.0, "UnderArmour"},   
        {110, 11, 1599.00,  5.0, "Uniqlo"}        
    };
    int choice;
    int i;
    do {
        printf("\n====WELCOME TO TRENDS===");
        printf("    ======MENU======\n");
        printf("1:View Inventory Stock\n");
        printf("2:Purchase Items\n");
        printf("3:Checkout & Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        while (choice < 1 || choice > 3) {
            printf("\nInvalid Choice please try again\n");
            printf("1:View Inventory Stock\n");
            printf("2:Purchase Items\n");
            printf("3:Checkout & Exit\n");
            printf("Enter Your Choice: ");
            scanf("%d", &choice);
        }
        if (choice == 1) {
            printf("\nProduct_ID\tBrand\t\tMRP\t\tDiscount%%\tAvailable_Qty\n");
            printf("-----------------------------------------------------------------------\n");
            for (i = 0; i < 10; i++) {
                printf("%d\t\t%-12s\tRs.%.2f\t\t%.1f%%\t\t%d\n", 
                       inventory[i].id, 
                       inventory[i].brand, 
                       inventory[i].mrp, 
                       inventory[i].discount, 
                       inventory[i].stock);
            }
        }
        else if (choice == 2) {
            int PI;
            int quantity;
            int found_index = -1; 
            printf("Enter the product ID: ");
            scanf("%d", &PI);
            for (i = 0; i < 10; i++) {
                if (PI == inventory[i].id) { 
                    found_index = i; 
                    break; 
                }
            }
            if (found_index != -1) {
                double original_mrp = inventory[found_index].mrp;
                double discount_pct = inventory[found_index].discount;
                double final_price = original_mrp - (original_mrp * (discount_pct / 100.0));
                printf("Product Found! Brand: %s | MRP: Rs.%.2f | Discount: %.1f%% | Final Price: Rs.%.2f\n", 
                       inventory[found_index].brand, original_mrp, discount_pct, final_price);
                printf("Available Stock: %d\n", inventory[found_index].stock);
                printf("Enter the Quantity of product: ");
                scanf("%d", &quantity);   
                if (quantity > 0 && quantity <= inventory[found_index].stock) {
                    printf("Quantity is Available\n");
                    inventory[found_index].stock = inventory[found_index].stock - quantity;
                    printf("Remaining stock inside structure for ID %d: %d\n", 
                           inventory[found_index].id, inventory[found_index].stock);           
                    double total_bill = final_price * quantity;
                    printf("Total cost for this item: Rs.%.2f\n", total_bill);
                } 
                else {
                    printf("Quantity is not available or invalid!\n");
                }
            } 
            else {
                printf("Enter a valid product ID (Product Not Found)\n");
            }
        }
        else if (choice == 3) {
            printf("\nThank you for shopping at Trends. Have a nice day!\n");
        }
    } while (choice != 3);
    return 0;
}