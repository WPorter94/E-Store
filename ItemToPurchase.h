
#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include <string>
#include <iostream>


class ItemToPurchase {
public:
    ItemToPurchase();
    //ItemToPurchase(const ItemToPurchase& orig);
    void SetName(std::string);
    std::string GetName();
    void SetPrice(int price);
    int GetPrice();
    void SetQuantity(int quantity);
    int GetQuantity();
    std::string GetDescription();
    void SetDescription(std::string);
    void PrintItemCost();
    void PrintItemDescription();

private:
    std::string itemName;
    int itemPrice;
    int itemQuantity;
    std::string itemDescription;
};

#endif /* ITEMTOPURCHASE_H */

