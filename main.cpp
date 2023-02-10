#include <iostream>
#include <cstdlib>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <string>
#include <vector>
#include<cstring>
using namespace std;

void PrintMenu(ShoppingCart);

int main(int argc, char** argv)
{
	string tempName;
	string tempDate;

	cout << "Enter customer's name:" << endl;
	getline(cin, tempName);
	cout << "Enter today's date:" << endl;
	getline(cin, tempDate);
	cout << endl << "Customer name: " << tempName << endl << "Today's date: " << tempDate << endl <<endl;
	ShoppingCart Cart1(tempName,tempDate);
	PrintMenu(Cart1);

	return 0;
}
void PrintMenu(ShoppingCart cart)
{
	char selection;
	ItemToPurchase Item1;
	ItemToPurchase Item2;
	string itemname;
	string itemdescription;
	int itemprice;
	int itemquantity;
	string itemtoremove;
	
	do {
cout << "MENU\na - Add item to cart\nd - Remove item from cart\nc \
- Change item quantity\ni - Output items' descriptions\no \
- Output shopping cart\nq - Quit\n\n";
		cout << "Choose an option:\n";
		cin >> selection;
		cin.ignore();
		while (selection != 'a' && selection != 'd' && selection != 'c' && selection != 'i' && selection != 'o' && selection != 'q')
		{
			cout << "Choose an option:\n";
			cin >> selection;
			cin.ignore();
		}
		switch (selection) {
		case 'a':
			cout << "ADD ITEM TO CART" << endl;
			cout << "Enter the item name:" << endl;
			getline(cin, itemname);
			Item1.SetName(itemname);
			cout << "Enter the item description:" << endl;
			getline(cin, itemdescription);
			Item1.SetDescription(itemdescription);
			cout << "Enter the item price:" << endl;
			cin >> itemprice;
			cin.ignore();
			Item1.SetPrice(itemprice);
			cout << "Enter the item quantity:" << endl;
			cin >> itemquantity;
			cin.ignore();
			Item1.SetQuantity(itemquantity);
			cart.AddItem(Item1);
			cout << endl;
			break;
		case 'd':
			cout << "REMOVE ITEM FROM CART\n" << "Enter name of item to remove:\n";
			getline(cin, itemtoremove);
			cart.RemoveItems(itemtoremove);
			cout << endl;
			break;
		case 'c':
			cout << "CHANGE ITEM QUANTITY\nEnter the item name:\n";
			getline(cin, itemname);
			Item2.SetName(itemname);
			cout << "Enter the new quantity:\n";
			cin >> itemquantity;
			Item2.SetQuantity(itemquantity);
			cart.ModifyItem(Item2);
			break;
		case 'i':
			cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
			cart.PrintDescriptions();
			break;
		case 'o':
			cout << "OUTPUT SHOPPING CART" << endl;
			cart.PrintTotal();
			break;
		case 'q':
			break;
		}
	} while (selection != 'q');
}