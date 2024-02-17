#include<stdio.h>
#include "../includes/hotel_managers.h"
//#include "../includes/inventory_managers.h"
#include "../includes/raw_item_managers.h"
#include "../includes/analyst.h"

void inventoryManagers();
void hotelManagers();
void analyst();

struct hotel_menu_schema *menu_head,*menu_tail;
struct inventory_schema *inventory_head,*inventory_tail;
int total_cash = 0;

int main(){
    menu_head = menu_tail = inventory_head = inventory_tail = NULL;
    int choice;
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
        default: printf("\nBye see you next time");
                return 0;
        }
    }
    return 0;
}

void inventoryManagers(){
    printf("\n\t\tINVENTORY MANAGEMENT SYSTEM\t\t\n");
    int choice;
    while (1)
    {
        printf("\n");
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
    }
    
}
void hotelManagers(){
    printf("\n\t\tHOTEL MANAGEMENT SYSTEM\t\t\n");
    int choice;
    while (1)
    {
        printf("\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:createItem(&menu_head,&menu_tail);
            break;
        case 2:removeItem(&menu_head,&menu_tail);
            break;
        case 3:updateItemPrice(menu_head);
            break;
        case 4:displayItem(menu_head);
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
    }
    
}
void analyst(){
    printf("\n\t\tANALYSIS SYSTEM\t\t\n");
    int choice;
    while (1)
    {
        printf("\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Total cash collted: %d",total_cash);
            break;
        case 2: profit(menu_head);
            break;
        case 3: topdish(menu_head);
        case 4: return 0;
        default: printf("\nInvalid Choice!...");
        }
    }
    
}