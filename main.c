//Assignment 4 main.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "item.h"


void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) // function placed pre-determined values into structs
{
    // Items_list contains: price, sku, catagory, name of size index which is hard set to 5 items
    item_list[index].name = name;
    item_list[index].sku = sku;
    item_list[index].category = category;
    item_list[index].price = price;
}


double average_price(Item *item_list, int size) // function calculates and returns average of the item_list.price
{
    double summedTotal = 0;
    int i;
    for (i = 0; i < size; i++) //loops through each item_list struct price and sums them
    {
        summedTotal = item_list[i].price + summedTotal;
    }
    return summedTotal/size;  //divides the sum by the number of the prices and returns the average price
}


void print_items(Item *item_list, int found_index, double average_price) // function loops through each item_list entry and prints the struct values, then prints the average of all item_list prices
{
    printf("\n\n###############");
    printf("Item Name = ");
    printf("%s", item_list[found_index].name); //prints selected item name

    printf("\nItem Sku = ");
    printf("%s", item_list[found_index].sku); //prints selected item sku

    printf("\nItem Catagory = ");
    printf("%s", item_list[found_index].category); //prints selected item category

    printf("\nItem Price = ");
    printf("%.2f", item_list[found_index].price); //prints selected item price

    printf("\n###############");
    printf("\n\nAverage Price of Items = "); //prints average price of all items
    printf("%.2f", average_price);
    printf("\n\n");  
}


void free_items(Item *item_list, int size)  // function frees the space from malloc of items_list struct
{
    int i;
    for (i = 0; i < size; i++) // loops through each item_list allocated data index and frees the memory for sku, name and catagory
    {
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }
    free(item_list); // frees the memory of the item_list struct
}


int main(int argc, char *argv[])
{
    if (argc < 2) //safety checks to see if user entered a sku value.  If not, aborts...
    {
        printf("No sku number entered by user.\n\nThis task is aborted!\n\n");
        return 1;
    }
    
    int size = 5;  // number of hard coded items in inventory
    double avgPrice;  //average price variable
    int count = 0;  //counter variable for while loop and index selection

    Item *item_list = malloc(size * sizeof(Item));  //allocates memory for struct based on hard coded 5 items in inventory

    //adds entries for the 5 hard coded items in inventory
    int i = 0;
    add_item(item_list, 5.000000, "19282", "breakfast", "reese's cereal", i);
    i++;
    add_item(item_list, 3.950000, "79862", "dairy", "milk", i);
    i++;
    add_item(item_list, 1.000000, "12345", "poultry", "eggs", i);
    i++;
    add_item(item_list, 2.000000, "23456", "grain", "rice", i);
    i++;
    add_item(item_list, 3.000000, "34567", "veggies", "peas", i);
    

    while (count < size && strcmp(argv[1], item_list[count].sku) != 0) // loops until user provided sku number is found in item_list.sku or until entire list is checked
    {
        count++; //increments to next row of inventory
    }

    printf("\nYou selected sku # = %s", argv[1]); //repeats the user's selected sku

    if (count == size) // if count = size, then the sku was not found
    {
        printf("\n\nSku # NOT found in list, sorry!\n\n"); // prints not found
    }

    else //if count != size, then the sku was found
    {
        printf("\n\nSku # found in list!"); // prints sku found
        avgPrice = average_price(item_list, size); // executes average price function calculcation
        print_items(item_list, count,  avgPrice); // executes print fucntion to print selected sku information and the average pricing
    }    

    free_items(item_list,  size); // executes function to free all allocated memory
}



