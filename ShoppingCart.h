#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <string>
#include <iostream>
#include <vector>
#include "ItemToPurchase.h"


class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(std::string customerName,std::string currentDate);
    std::string GetCustomerName();
    std::string GetDate();
    void AddItem(ItemToPurchase);
    void RemoveItems(std::string);
    void ModifyItem(ItemToPurchase);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();

private:
    std::string customerName;
    std::string currentDate;
    std::vector<ItemToPurchase> cartItems;
};

#endif /* SHOPPINGCART_H */




