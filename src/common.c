#include<stdio.h>
#include "../includes/common.h"

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