#ifndef ANALYST_H
#define ANALYST_H

#include "hotel_menu_schema.h"
#include "inventory_schema.h"
#include "raw_item_schema.h"

int totalAmount(char dishname[],int quantity);
void deductor(struct hotel_menu_schema *menu_head);
void searchRaw(struct raw_item *head,int sold_count);
#endif