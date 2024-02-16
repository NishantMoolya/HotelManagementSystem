#ifndef INVENTORY_SCHEMA_H
#define INVENTORY_SCHEMA_H
#define SIZE 15
struct inventory_schema
{
    char item_name[SIZE];
    int item_stock;
    struct inventory_schema *next;
};

#endif