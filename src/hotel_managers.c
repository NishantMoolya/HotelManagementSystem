#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../includes/hotel_managers.h"
#include "../includes/raw_item_managers.h"
#include "../includes/analyst.h"

void createItem(struct hotel_menu_schema **menu_head,struct hotel_menu_schema **menu_tail){
    struct raw_item *temp = NULL,*raw_tail;
    struct hotel_menu_schema *menu_new = (struct hotel_menu_schema*)malloc(sizeof(struct hotel_menu_schema));
    printf("\nEnter the dish name:");
    scanf("%s",menu_new->dish_name);
    printf("\nEnter the price of %s:",menu_new->dish_name);
    scanf("%d",&menu_new->price);
    printf("\nEnter the profit margin of %s:",menu_new->dish_name);
    scanf("%f",&menu_new->profit_percentage);
    menu_new->next = NULL;
    menu_new->link = NULL;
    menu_new->sold_count = 0;
    if (*menu_head == NULL)
    {
        *menu_head = *menu_tail = menu_new;
    }else{
        (*menu_tail)->next = menu_new;
        *menu_tail = menu_new;
    }
    printf("\nEnter the raw materials required to prepare %s\n",menu_new->dish_name);
    int choice = 1;
    while (choice)
    {
    temp = addRawMaterials();
    printf("%s",temp);
    if (menu_new->link == NULL)
    {
        menu_new->link = temp;
        raw_tail = temp;
    }else{
        raw_tail->next = temp;
        raw_tail = temp;
    }
    printf("\nPress 0 if all the raw materials are entered\nPress 1 to continue:");
    scanf("%d",&choice);
    }
}

int removeItem(struct hotel_menu_schema **menu_head,struct hotel_menu_schema **menu_tail){
    char item_name[SIZE];
    struct hotel_menu_schema *temp,*prev;
    temp = *menu_head;
    if (*menu_head == NULL)
    {
        printf("\nNo dish available in the menu");
    }else
    {
    printf("\nEnter the item name that has to be removed from menu:");
    scanf("%s",item_name);
    while (temp != NULL)
    {
        if (!strcmp(temp->dish_name,item_name))
        {
            if (temp == *menu_head && (*menu_head)->next == NULL)
            {
                *menu_head = *menu_tail = NULL;
            }else if (temp == *menu_tail)
            {
                prev->next = NULL;
                *menu_tail = prev;
            }else{
                prev->next = temp->next;
            }
            removeRawMaterials(temp->link);
            free(temp);
            printf("\nDish found and removed from menu");
            return 0;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("\nDish not found in menu");
    }
}

void displayItem(struct hotel_menu_schema *menu_head){
    struct hotel_menu_schema *temp;
    int i = 0;
    if (menu_head == NULL)
    {
        printf("\nNo dish available in the menu");
    }else{
    temp = menu_head;
    printf("\nDish Names are:\n");
    while (temp != NULL)
    {
        printf("\nDish No. %d: %s",++i,temp->dish_name);
        temp = temp->next;
    }
    }
}

int updateItemPrice(struct hotel_menu_schema *menu_head){
    struct hotel_menu_schema *temp;
    char item_name[SIZE];
    int new_price;
    printf("\nEnter the item name whose price has to be updated in menu:");
    scanf("%s",item_name);
    printf("\nEnter the new price:");
    scanf("%d",&new_price);
    temp = searchDish(menu_head,item_name);
    if (temp != NULL)
    {
        temp->price = new_price;
        printf("\nItem price updated successfully");
    }
}

int getItemDetails(struct hotel_menu_schema *menu_head){
    struct hotel_menu_schema *temp;
    char item_name[SIZE];
    printf("\nEnter the dish name:");
    scanf("%s",item_name);
    temp = searchDish(menu_head,item_name);
    if (temp != NULL)
    {
        printf("\nDish Name:\t%s\nPrice:\t%d\nProfit Margin:\t%.2f",temp->dish_name,temp->price,temp->profit_percentage);
    }else{
        printf("\nDish not present in menu");
    }
}


//only here is the problem above done
void createOrderAndBill(struct hotel_menu_schema *menu_head){
    char ordered_dish[10][15];
    int ordered_plates[10];
    int i = 0;
    int choice = 1;
    while (choice)
    { 
    printf("\nEnter dish:");
    scanf("%s",ordered_dish[i]);
    printf("\nEnter number of plates:");
    scanf("%d",&ordered_plates[i]);
    printf("\nPress 1 to continue.\nPress 0 to end");
    scanf("%d",&choice);
    i++;
    }
    printf("\nList of:\n");
    int total_amount = 0;
    for (int j = 0; j < i; j++)
    {
        total_amount += totalAmount(menu_head,ordered_dish[j],ordered_plates[j]);
        printf("\n%s\t\t%d",ordered_dish[j],ordered_plates[j]);
        printf("\nTotal:\t\t%d",total_amount);
    }
}