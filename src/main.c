#include<stdio.h>
#include "../includes/hotel_managers.h"
#include "../includes/inventory_managers.h"
#include "../includes/raw_item_managers.h"
#include "../includes/analyst.h"

int inventoryManagers();
int hotelManagers();
int analyst();

struct hotel_menu_schema *menu_head,*menu_tail;
struct inventory_schema *inventory_head,*inventory_tail;
int total_cash = 0;

int main(){
    menu_head = menu_tail = NULL;
    inventory_head = inventory_tail = NULL;
    int choice;
    printf("\n=============================================================================================");
    while (1)
    {
        printf("\n1.Manage Inventory\n2.Manage Hotel\n3.Analyze business\nPress others to Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: inventoryManagers();
            break;
        case 2: hotelManagers();
            break;
        case 3: analyst();
            break;
        default: freeMenuMemory(menu_head);
                 freeInventoryMemory(inventory_head); 
                 return 0;
        }
        printf("\n=============================================================================================");
    }
    return 0;
}

int inventoryManagers(){
    printf("\n\t\tINVENTORY MANAGEMENT SYSTEM\t\t\n");
    int choice;
    while (1)
    {
        printf("\n=============================================================================================");
        printf("\n1.Add stock to inventory\n2.Remove stock from inventory\n3.View inventory\n4.Update stock quantity\n5.Get details of stock\n6.Exit\n");
        printf("\n=============================================================================================");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: addStock(&inventory_head,&inventory_tail);
            break;
        case 2: removeStock(&inventory_head,&inventory_tail);
            break;
        case 3: displayStock(inventory_head);
            break;
        case 4: updateQuantity(inventory_head);
            break;
        case 5: getStockDetails(inventory_head);
            break;
        case 6: return 0;
        default: printf("\nInvalid Choice!...");
        }
        printf("\n=============================================================================================");
    }
    
}
int hotelManagers(){
    printf("\n\t\tHOTEL MANAGEMENT SYSTEM\t\t\n");
    int choice;
    while (1)
    {
        printf("\n=============================================================================================");
        printf("\n1.Add dish to menu\n2.Remove dish from menu\n3.View menu\n4.Update dish price\n5.Get details of dish\n6.Get details of raw materials used\n7.Take order and create bill\n8.Exit\n");
        printf("\n=============================================================================================");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:createItem(&menu_head,&menu_tail);
            break;
        case 2:removeItem(&menu_head,&menu_tail);
            break;
        case 3:displayItem(menu_head);
            break;
        case 4:updateItemPrice(menu_head);
            break;
        case 5:getItemDetails(menu_head);
            break;
        case 6:displayRawMaterials(menu_head);
            break;
        case 7:total_cash += createOrderAndBill(menu_head);
            break;
        case 8: return 0;
        default: printf("\nInvalid Choice!...");
        }
        printf("\n=============================================================================================");
    }
    
}
int analyst(){
    printf("\n\t\tANALYSIS SYSTEM\t\t\n");
    int choice;
    while (1)
    {
        printf("\n=============================================================================================");
        printf("\n1.Get total cash collected\n2.Show profit\n3.Show Top dish sold\n4.Update Inventory\n5.Exit\n");
        printf("\n=============================================================================================");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Total cash collected: %d",total_cash);
            break;
        case 2: profit(menu_head);
            break;
        case 3: topdish(menu_head);
            break;
        case 4: deductor(menu_head,inventory_head);
            break;
        case 5: return 0;
        default: printf("\nInvalid Choice!...");
        }
        printf("\n=============================================================================================");
    }
    
}