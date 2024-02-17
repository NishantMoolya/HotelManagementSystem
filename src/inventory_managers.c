#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../includes/inventory_schema.h"
#include "../includes/analyst.h"

void addStock(struct inventory_schema **inventory_head,struct inventory_schema **inventory_tail){
    struct inventory_schema *inventory_new = (struct inventory_schema*)malloc(sizeof(struct inventory_schema));
    printf("\nEnter the item name:");
    scanf("%s",inventory_new->item_name);
    printf("Enter the qauntity of %s:",inventory_new->item_name);
    scanf("%d",&inventory_new->item_stock);
    inventory_new->next = NULL;
    if (*inventory_head == NULL)
    {
        *inventory_head = *inventory_tail = inventory_new;
    }else{
        (*inventory_tail)->next = inventory_new;
        *inventory_tail = inventory_new;
    }
}

int removeStock(struct inventory_schema **inventory_head,struct inventory_schema **inventory_tail){
    char item_name[SIZE];
    struct inventory_schema *temp,*prev;
    temp = *inventory_head;
    if (*inventory_head == NULL)
    {
        printf("\nNo raw material available in the inventory");
    }else
    {
    printf("\nEnter the item name that has to be removed from inventory:");
    scanf("%s",item_name);
    while (temp != NULL)
    {
        if (!strcmp(temp->item_name,item_name))
        {
            if (temp == *inventory_head && (*inventory_head)->next == NULL)
            {
                *inventory_head = *inventory_tail = NULL;
            }else if (temp == *inventory_tail)
            {
                prev->next = NULL;
                *inventory_tail = prev;
            }else{
                prev->next = temp->next;
            }
            free(temp);
            printf("\nItem found and removed from inventory");
            return 0;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("\nItem not found in inventory");
    }
}

void displayStock(struct inventory_schema *inventory_head){
    struct inventory_schema *temp;
    int i = 0;
    if (inventory_head == NULL)
    {
        printf("\nNo raw items available in the menu");
    }else{
    temp = inventory_head;
    printf("\nItem Names are:\n");
    while (temp != NULL)
    {
        printf("\nItem No. %d: %s",++i,temp->item_name);
        temp = temp->next;
    }
    }
}

void updateQuantity(struct inventory_schema *inventory_head){
    struct inventory_schema *temp;
    char item_name[SIZE];
    int new_quantity;
    printf("\nEnter the item name whose quantity has to be updated in inventory:");
    scanf("%s",item_name);
    printf("\nEnter the new quantity:");
    scanf("%d",&new_quantity);
    temp = searchInventory(inventory_head,item_name);
    if (temp != NULL)
    {
        temp->item_stock = new_quantity;
        printf("\nItem quantity updated successfully");
    }
}

void getStockDetails(struct inventory_schema *inventory_head){
    struct inventory_schema *temp;
    char item_name[SIZE];
    printf("\nEnter the item name:");
    scanf("%s",item_name);
    temp = searchInventory(inventory_head,item_name);
    if (temp != NULL)
    {
        printf("\nItem Name:\t%s\nQuantity:\t%d\n",temp->item_name,temp->item_stock);
    }else{
        printf("\nItem not present in inventory");
    }
}