#ifndef HOTEL_MANAGERS_H
#define HOTEL_MANAGERS_H

#include "hotel_menu_schema.h"
#include "raw_item_schema.h"

void createItem(struct hotel_menu_schema **menu_head,struct hotel_menu_schema **menu_tail);
int removeItem(struct hotel_menu_schema **menu_head,struct hotel_menu_schema **menu_tail);
void displayItem(struct hotel_menu_schema *menu_head);
int updateItemPrice(struct hotel_menu_schema *menu_head);
int getItemDetails(struct hotel_menu_schema *menu_head);
int createOrderAndBill(struct hotel_menu_schema *menu_head);

#endif