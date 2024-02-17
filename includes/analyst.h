#ifndef ANALYST_H
#define ANALYST_H

#include "hotel_menu_schema.h"
#include "inventory_schema.h"
#include "raw_item_schema.h"

struct hotel_menu_schema* searchDish(struct hotel_menu_schema *menu_head,char name[]);
int totalAmount(struct hotel_menu_schema *menu_head,char dishname[],int quantity);
void deductor(struct hotel_menu_schema *menu_head);
void searchRaw(struct raw_item *head,int sold_count);
#endif