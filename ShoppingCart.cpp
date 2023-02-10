#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <iostream>
#include <string>
#include <vector>
#include<cstring>
using namespace std;
ShoppingCart::ShoppingCart()
{
	this->customerName = "none";
	this->currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(std::string customerName, std::string currentDate)
{
	this->customerName = customerName;
	this->currentDate = currentDate;
}
std::string ShoppingCart::GetCustomerName()
{
	return this->customerName;
}
std::string ShoppingCart::GetDate()
{
	return this->currentDate;
}
void ShoppingCart::AddItem(ItemToPurchase object)
{
	cartItems.push_back(object);
}
void ShoppingCart::RemoveItems(std::string stringorig)
{
	
	for (int i = 0;i < cartItems.size();i++)
	{
		if (cartItems.at(i).GetName() == stringorig)
		{
			cartItems.erase(cartItems.begin() + i);
			return;
		}
	}
	cout << "Item not found in cart. Nothing removed." << endl;
}
void ShoppingCart::ModifyItem(ItemToPurchase searchitem)
{
	for (int i = 0; i < cartItems.size(); i++)
	{
		if (cartItems.at(i).GetName() == searchitem.GetName())
		{
			if ((searchitem.GetDescription() != "None") || (searchitem.GetPrice() != 0) || (searchitem.GetQuantity() != 0))
			{
				cartItems.at(i).SetDescription(searchitem.GetDescription());
				//cartItems.at(i).SetPrice(searchitem.GetPrice());
				cartItems.at(i).SetQuantity(searchitem.GetQuantity());
			}
		}
		if ((cartItems.at(i).GetName() != searchitem.GetName()) && (i + 1 == cartItems.size()))
		{
			cout << "Item not found in cart. Nothing modified." << endl << endl;
		}
	}
}
int ShoppingCart::GetNumItemsInCart()
{
	int totalquantity = 0;

	for (int i = 0; i < cartItems.size(); i++)
	{
		totalquantity = totalquantity + cartItems.at(i).GetQuantity();
	}
	return totalquantity;
}
int ShoppingCart::GetCostOfCart()
{
	int totalcost = 0;

	for (int i = 0; i < cartItems.size(); i++)
	{
		totalcost = totalcost + (cartItems.at(i).GetQuantity()* cartItems.at(i).GetPrice());
	}
	return totalcost;
}
void ShoppingCart::PrintTotal()
{
	cout << this->GetCustomerName()<< "'s Shopping Cart - " << this->GetDate()<< endl <<"Number of Items: " << this->GetNumItemsInCart() << endl << endl;
	int totalcost = 0;
	for (int i = 0; i < cartItems.size(); i++)
	{
		if (cartItems.at(i).GetQuantity() > 0)
		{
			cout << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $" << cartItems.at(i).GetPrice() << \
				" = $" << (cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice()) << endl; 

			totalcost = totalcost + (cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice());
		}
	}
	if (totalcost == 0)
	{
		cout << "SHOPPING CART IS EMPTY" << endl;
	}
	
	cout << "\nTotal: $" << totalcost << endl << endl;
	
}
void ShoppingCart::PrintDescriptions()
{
	cout << this->GetCustomerName() << "'s Shopping Cart - " << this->GetDate() << endl << endl << "Item Descriptions" << endl;
	for (int i = 0; i < cartItems.size(); i++)
	{
		if (cartItems.at(i).GetQuantity() > 0)
		{
			cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription() << endl;
		}
	}
	cout << endl;
}

