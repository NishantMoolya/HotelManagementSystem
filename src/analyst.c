#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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

struct inventory_schema* searchInventory(struct inventory_schema *inventory_head,char raw_material[]){
    if(inventory_head == NULL){
        printf("\nNo raw items available in inventory");
        return NULL;
    }else{
    struct inventory_schema *raw;
    raw = inventory_head;
    while (raw != NULL)
    {
        if(!strcmp(raw->item_name,raw_material)){
            return raw;
        }
        raw = raw->next;
    }
    printf("\nInvalid raw item name");
    return NULL;
    }
}

void searchRaw(struct raw_item *head,struct inventory_schema *inventory_head,int sold_count){
    struct inventory_schema *temp;
    if(head != NULL){
        while (head != NULL)
        {
            temp = searchInventory(inventory_head,head->raw_item_name);
            if(temp != NULL){
                temp->item_stock -= (head->quantity_used)*sold_count;
            }
            head = head->next;
        }
        
    }
}

void deductor(struct hotel_menu_schema *menu_head,struct inventory_schema *inventory_head){
    struct hotel_menu_schema *temp;
    temp = menu_head;
    while (temp != NULL)
    {
        if(temp->sold_count){
        searchRaw(temp->link,inventory_head,temp->sold_count);
        }
        temp = temp->next;
    }
    printf("\nInventory updated successfully.");
}

int totalAmount(struct hotel_menu_schema *menu_head,char dishname[],int quantity){
    struct hotel_menu_schema *temp;
    int total_amount;
    temp = searchDish(menu_head,dishname);
    total_amount = (temp->price)*quantity;
    temp->sold_count += quantity;
    return total_amount;
}

void profit(struct hotel_menu_schema *menu_head){
    struct hotel_menu_schema *temp;
    float profit = 0;
    if (menu_head == NULL)
    {
        printf("\nNo dish available in menu");
    }else{
        temp = menu_head;
        while (temp != NULL)
        {
            if (temp->sold_count)
            {
                profit += (((temp->profit_percentage)/100)*(temp->price)*(temp->sold_count));
            }
            temp = temp->next;
        }
        printf("\nTotal profit to business: Rs %.2f",profit);
    }
}

void topdish(struct hotel_menu_schema *menu_head){
    struct hotel_menu_schema *temp,*top;
    int count = 0;
    if (menu_head == NULL)
    {
       printf("\nNo dish available in menu");
    }else{
        temp = menu_head;
        while (temp != NULL)
        {
            if(top->sold_count < temp->sold_count){
                top = temp;
            }
            temp = temp->next;
        }
        printf("\nTop selling dish is: %s and %d plates were sold",top->dish_name,top->sold_count);
    }
}
// void sort(struct hotel_menu_schema **menu_head){   //sort functionality is incomplete(selection sort)
//     struct hotel_menu_schema *temp,*temp1,*temp2,*prev;
//     char topdish[3][15];
//     if (*menu_head == NULL)
//     {
//         printf("\nNo dish available in menu");
//     }else{
//         temp = *menu_head;
//         while (temp != NULL)
//         {
//             while (temp1 != NULL)
//             {
//                 if(temp->sold_count < temp1->sold_count){
//                     temp2 = temp->next;
//                     temp->next = temp1->next;
//                     temp1->next = temp2;
//                     prev->next = temp;
//                 }
//                 prev = temp1;
//                 temp1 = temp1->next;
//             }
//             temp = temp->next;
//         }
        
//     }
// }

void freeRawMemory(struct raw_item *head){
    struct raw_item *temp;
    if (head != NULL)
    {
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        
    }
    
}

void freeMenuMemory(struct hotel_menu_schema *head){
    struct hotel_menu_schema *temp;
    if (head != NULL)
    {
        while (head != NULL)
        {
            freeRawMemory(head->link);
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    printf("\nBye see you next time-Created by Nishant Moolya");
}

void freeInventoryMemory(struct inventory_schema *head){
    struct inventory_schema *temp;
    if (head != NULL)
    {
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    
}