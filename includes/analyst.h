#ifndef ANALYST_H
#define ANALYST_H

#include "hotel_menu_schema.h"
#include "inventory_schema.h"
#include "raw_item_schema.h"

struct hotel_menu_schema* searchDish(struct hotel_menu_schema *menu_head,char name[]);
int totalAmount(struct hotel_menu_schema *menu_head,char dishname[],int quantity);
void deductor(struct hotel_menu_schema *menu_head,struct inventory_schema *inventory_head);
void searchRaw(struct raw_item *head,struct inventory_schema *inventory_head,int sold_count);
struct inventory_schema* searchInventory(struct inventory_schema *inventory_head,char raw_material[]);
void profit(struct hotel_menu_schema *menu_head);
void topdish(struct hotel_menu_schema *menu_head);
void freeRawMemory(struct raw_item *head);
void freeMenuMemory(struct hotel_menu_schema *head);
void freeInventoryMemory(struct inventory_schema *head);

#endif