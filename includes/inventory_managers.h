#ifndef INVENTORY_MANAGERS_H
#define INVENTORY_MANAGERS_H

#include "inventory_schema.h"

struct inventory_schema* searchInventory(struct inventory_schema *inventory_head,char raw_material[]);

#endif