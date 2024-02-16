#include<stdio.h>
#include "../includes/hotel_managers.h"
#include "../includes/inventory_managers.h"
#include "../includes/raw_item_managers.h"
#include "../includes/analyst.h"

void inventoryManagers();
void hotelManagers();
void analyst();

struct hotel_menu_schema *menu_head,*menu_tail,*menu_new;
struct inventory_schema *inventory_head,*inventory_tail;

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
        case 1:
            break;
        case 2: return 0;
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
        case 1:createItem();
            break;
        case 2:removeItem();
            break;
        case 3:updateItemPrice();
            break;
        case 4:displayItem();
            break;
        case 5:getItemDetails();
            break;
        case 6:displayRawMaterials();
            break;
        case 7:createOrderAndBill();
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
        case 1:
            break;
        case 2: return 0;
        default: printf("\nInvalid Choice!...");
        }
    }
    
}