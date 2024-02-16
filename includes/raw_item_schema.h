#ifndef RAW_ITEM_SCHEMA_H
#define RAW_ITEM_SCHEMA_H
#define SIZE 15
struct raw_item
{
    char raw_item_name[SIZE];
    int quantity_used;
    struct raw_item *next;
};

#endif