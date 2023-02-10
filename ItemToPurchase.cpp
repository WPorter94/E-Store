#include <iostream>
#include <string>
#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase() {
    this->itemName = "None";
    this->itemPrice = 0;
    this->itemQuantity = 0;
    this->itemDescription = "None";
}
void ItemToPurchase::SetName(std::string name) 
{
    this->itemName = name;
}
std::string ItemToPurchase::GetName() 
{
    return this->itemName;
}
void ItemToPurchase::SetPrice(int price) 
{
    this->itemPrice = price;
}
int ItemToPurchase::GetPrice() 
{
    return this->itemPrice;
}
void ItemToPurchase::SetQuantity(int quantity) 
{
    this->itemQuantity = quantity;
}
int ItemToPurchase::GetQuantity() 
{
    return this->itemQuantity;
}
void ItemToPurchase::PrintItemCost() 
{
    int total = this->itemPrice * this->itemQuantity;
    cout << this->itemName << " " << this->itemQuantity << " @ $" << this->itemPrice << " = $" << total << endl;
}
void ItemToPurchase::PrintItemDescription() 
{
    cout << itemName << ": " << itemDescription << endl;
}
void ItemToPurchase::SetDescription(std::string description)
{
    this->itemDescription = description;
}
std::string ItemToPurchase::GetDescription()
{
    return this->itemDescription;
}