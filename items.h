#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>

typedef struct _Item {
    double price;
    char *sku;
    char *name;
    char *category;
} Item;

#endif
