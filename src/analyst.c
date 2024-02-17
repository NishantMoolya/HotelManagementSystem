#include<stdio.h>
#include "../includes/analyst.h"

struct hotel_menu_schema* searchDish(struct hotel_menu_schema *menu_head,char name[]){
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

void searchRaw(struct raw_item *head,int sold_count){
    struct inventory_schema *temp;
    if(head != NULL){
        while (head != NULL)
        {
            temp = searchInventory(head->raw_item_name);
            if(temp != NULL){
                temp->item_stock -= (head->quantity_used)*sold_count;
            }
            head = head->next;
        }
        
    }
}

void deductor(struct hotel_menu_schema *menu_head){
    struct hotel_menu_schema *temp;
    temp = menu_head;
    while (temp != NULL)
    {
        if(temp->sold_count){
        searchRaw(temp->link,temp->sold_count);
        }
        temp = temp->next;
    }
}

int totalAmount(struct hotel_menu_schema *menu_head,char dishname[],int quantity){
    struct hotel_menu_schema *temp;
    int total_amount;
    temp = searchDish(menu_head,dishname);
    total_amount = (temp->price)*quantity;
    temp->sold_count += quantity;
    return total_amount;
}