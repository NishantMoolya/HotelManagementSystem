#ifndef INVENTORY_MANAGERS_H
#define INVENTORY_MANAGERS_H

#include "inventory_schema.h"

void addStock(struct inventory_schema **inventory_head,struct inventory_schema **inventory_tail);
void removeStock(struct inventory_schema **inventory_head,struct inventory_schema **inventory_tail);
void displayStock(struct inventory_schema *inventory_head);
void updateQuantity(struct inventory_schema *inventory_head);
void getStockDetails(struct inventory_schema *inventory_head);

#endif