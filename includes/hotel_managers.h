#ifndef HOTEL_MANAGERS_H
#define HOTEL_MANAGERS_H

#include "hotel_menu_schema.h"
#include "raw_item_schema.h"

void createItem();
void displayItem();
int removeItem();
int updateItemPrice();
int getItemDetails();
void createOrderAndBill();

#endif