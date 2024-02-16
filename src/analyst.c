#include<stdio.h>
#include "../includes/analyst.h"
#include "../includes/common.h"

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

int totalAmount(char dishname[],int quantity){
    struct hotel_menu_schema *temp;
    int total_amount;
    temp = searchDish(dishname);
    total_amount = (temp->price)*quantity;
    temp->sold_count += quantity;
    return total_amount;
}