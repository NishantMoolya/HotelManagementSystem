#ifndef RAW_ITEM_MANAGERS
#define RAW_ITEM_MANAGERS

#include "raw_item_schema.h"
#include "hotel_menu_schema.h"

struct raw_item* addRawMaterials();
void displayRawMaterials(struct hotel_menu_schema *menu_head);
void removeRawMaterials(struct raw_item *link);

#endif