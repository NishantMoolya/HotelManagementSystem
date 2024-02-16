#ifndef RAW_ITEM_MANAGERS
#define RAW_ITEM_MANAGERS

#include "raw_item_schema.h"
#include "hotel_menu_schema.h"
#include "common.h"

struct raw_item* addRawMaterials();
void displayRawMaterials();
void removeRawMaterials(struct raw_item *link);

#endif