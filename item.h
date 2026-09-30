//Assignment 4 item.h
struct _Item  // establishes stuct with price, sku, name and catagory
{
  double price;
  char *sku;
  char *name;
  char *category;
};
typedef struct _Item Item;
