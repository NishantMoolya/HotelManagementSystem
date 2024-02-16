#include<stdio.h>
#include "../includes/inventory_schema.h"

struct inventory_schema *inventory_head,*inventory_tail;

struct inventory_schema* searchInventory(char raw_material[]){
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
    printf("\nInvalid dish name");
    return NULL;
    }
}