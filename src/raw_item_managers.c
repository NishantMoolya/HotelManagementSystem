#include<stdio.h>
#include "../includes/raw_item_managers.h"
#include "../includes/analyst.h"

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

void displayRawMaterials(struct hotel_menu_schema *menu_head){
    char item_name[SIZE];
    printf("\nEnter the dish name:");
    scanf("%s",item_name);
    struct hotel_menu_schema *temp;
    temp = searchDish(menu_head,item_name);
    struct raw_item *ptr_to_rawlist;
    ptr_to_rawlist = temp->link;
    while (ptr_to_rawlist != NULL)
    {
        printf("\n%s %d",ptr_to_rawlist->raw_item_name,ptr_to_rawlist->quantity_used);
        ptr_to_rawlist = ptr_to_rawlist->next;
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