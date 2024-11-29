#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "items.h"

// Func
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);
void search_item(Item *item_list, int size, char *sku);

int main(int argc, char *argv[]) {
    //allocate mem
    int size = 5;
    Item *item_list = (Item *)malloc(size * sizeof(Item));
    if (!item_list) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Add 
    add_item(item_list, 2.50, "19282", "candy", "Reese", 0);
    add_item(item_list, 3.95, "79862", "dairy", "Milk", 1);
    add_item(item_list, 2.50, "12456", "snacks", "Doritos", 2);
    add_item(item_list, 2.89, "44567", "beverage", "Dr. Pepper", 3);
    add_item(item_list, 4.25, "54321", "produce", "Apples", 4);

    // Print 
    print_items(item_list, size);

    // Calc and print avg price
    printf("Avg price of items = %.6f\n", average_price(item_list, size));

    if (argc == 2) {
        printf("\nSearching for SKU: %s\n", argv[1]);
        search_item(item_list, size, argv[1]);
    }

    // Clear allocated mem
    free_items(item_list, size);
    return 0;
}

// Func implement
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
    item_list[index].price = price;

    item_list[index].sku = (char *)malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);

    item_list[index].category = (char *)malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);

    item_list[index].name = (char *)malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].category);
        free(item_list[i].name);
    }
    free(item_list);
}

double average_price(Item *item_list, int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += item_list[i].price;
    }
    return total / size;
}

void print_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %.6f\n", item_list[i].price);
    }
    printf("###############\n");
}

void search_item(Item *item_list, int size, char *sku) {
    int ct = 0;

    // Loop until match or end
    while (ct < size && strcmp(item_list[ct].sku, sku) != 0) {
        ct++;
    }

    if (ct < size) {
        printf("Item found:\n");
        printf("item name = %s\n", item_list[ct].name);
        printf("item sku = %s\n", item_list[ct].sku);
        printf("item category = %s\n", item_list[ct].category);
        printf("item price = %.6f\n", item_list[ct].price);
    } else {
        printf("Item not found.\n");
    }
}

