#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../includes/raw_item_managers.h"
#define SIZE 15
struct raw_item
{
    char raw_item_name[SIZE];
    int quantity_used;
    struct raw_item *next;
};

struct hotel_menu_schema
{
    char dish_name[SIZE];
    int price;
    float profit_percentage;
    int sold_count;
    struct raw_item *link;
    struct hotel_menu_schema *next;
};

struct inventory_schema
{
    char item_name[SIZE];
    int item_stock;
    struct inventory_schema *next;
};

struct hotel_menu_schema *menu_head,*menu_tail,*menu_new;
struct raw_item* addRawMaterials();
struct hotel_menu_schema* searchDish(char name[]);
void displayRawMaterials();
void removeRawMaterials(struct raw_item *head);
void deductor();
int totalAmount(char dishname[],int quantity);

void createItem(){
    struct raw_item *temp = NULL,*raw_tail;
    menu_new = (struct hotel_menu_schema*)malloc(sizeof(struct hotel_menu_schema));
    printf("\nEnter the dish name:");
    scanf("%s",menu_new->dish_name);
    printf("\nEnter the price of %s:",menu_new->dish_name);
    scanf("%d",&menu_new->price);
    printf("\nEnter the profit margin of %s:",menu_new->dish_name);
    scanf("%f",&menu_new->profit_percentage);
    menu_new->next = NULL;
    menu_new->link = NULL;
    menu_new->sold_count = 0;
    if (menu_head == NULL)
    {
        menu_head = menu_tail = menu_new;
    }else{
        menu_tail->next = menu_new;
        menu_tail = menu_new;
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

int removeItem(){
    char item_name[SIZE];
    struct hotel_menu_schema *temp,*prev;
    temp = menu_head;
    if (menu_head == NULL)
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
            if (temp == menu_head && menu_head->next == NULL)
            {
                menu_head = menu_tail = NULL;
            }else if (temp == menu_tail)
            {
                prev->next = NULL;
                menu_tail = prev;
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

void displayItem(){
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

int updateItemPrice(){
    struct hotel_menu_schema *temp;
    char item_name[SIZE];
    int new_price;
    printf("\nEnter the item name whose price has to be updated in menu:");
    scanf("%s",item_name);
    printf("\nEnter the new price:");
    scanf("%d",&new_price);
    temp = searchDish(item_name);
    if (temp != NULL)
    {
        temp->price = new_price;
        printf("\nItem price updated successfully");
    }
}

int getItemDetails(){
    struct hotel_menu_schema *temp;
    char item_name[SIZE];
    printf("\nEnter the dish name:");
    scanf("%s",item_name);
    temp = searchDish(item_name);
    if (temp != NULL)
    {
        printf("\nDish Name:\t%s\nPrice:\t%d\nProfit Margin:\t%.2f",temp->dish_name,temp->price,temp->profit_percentage);
    }else{
        printf("\nDish not present in menu");
    }
}

struct raw_item* addRawMaterials(){
    struct raw_item *raw_new = NULL;
    raw_new = (struct raw_item*)malloc(sizeof(struct raw_item));
    printf("\nEnter the name of raw material required:");
    scanf("%s",raw_new->raw_item_name);
    printf("\nEnter the quantity required:");
    scanf("%d",&raw_new->quantity_used);
    raw_new->next = NULL;
    return raw_new;
}

void displayRawMaterials(){
    char item_name[SIZE];
    printf("\nEnter the dish name:");
    scanf("%s",item_name);
    struct hotel_menu_schema *temp;
    temp = searchDish(item_name);
    struct raw_item *ptr_to_rawlist;
    ptr_to_rawlist = temp->link;
    while (ptr_to_rawlist != NULL)
    {
        printf("\n%s %d",ptr_to_rawlist->raw_item_name,ptr_to_rawlist->quantity_used);
        ptr_to_rawlist = ptr_to_rawlist->next;
    }
}

struct hotel_menu_schema* searchDish(char name[]){
    if(menu_head == NULL){
        printf("\nNo dish available in menu");
        return NULL;
    }else{
    struct hotel_menu_schema *dish;
    dish = menu_head;
    while (dish != NULL)
    {
        if(!strcmp(dish->dish_name,name)){
            return dish;
        }
        dish = dish->next;
    }
    printf("\nInvalid dish name");
    return NULL;
    }
}

void removeRawMaterials(struct raw_item *link){
    struct raw_item *temp;
    if (link != NULL)
    {
    while (link != NULL)
    {
        printf("%s",link->raw_item_name);
        temp = link;
        link = link->next;
        free(temp);
    }
    }else{
        printf("\nThe dish didn't had any raw material included");
    }
}

void createOrderAndBill(){
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
        total_amount += totalAmount(ordered_dish[j],ordered_plates[j]);
        printf("\n%s\t\t%d",ordered_dish[j],ordered_plates[j]);
        printf("\nTotal:\t\t%d",total_amount);
    }
}

int main(){
    menu_head = menu_tail = NULL;
    int choice;
    while (1)
    {
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
            break;
        default: printf("Invalid choice");
            break;
        }
    }
    return 0;
}