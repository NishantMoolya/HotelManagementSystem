#ifndef HOTEL_MENU_SCHEMA_H
#define HOTEL_MENU_SCHEMA_H
#define SIZE 15
#include "raw_item_schema.h"
struct hotel_menu_schema
{
    char dish_name[SIZE];
    int price;
    float profit_percentage;
    int sold_count;
    struct raw_item *link;
    struct hotel_menu_schema *next;
};

#endif