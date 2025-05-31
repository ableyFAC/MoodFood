#ifndef MENULIST_H
#define MENULIST_H

#include "RestaurantsList.h"
#include "Menu.h"

#include <map>
#include <vector>

using namespace std;

class MenuList
{
public:

	void addMenuItem(Category cat, const Menu& item);

	Category convert(const std::string& category);

	void printAppetizers(std::string restaurant);

	void printEntrees(std::string restaurant);

	void printSpecials(std::string restaurant);

	void printDrinks(std::string restaurant);

	void printDesserts(std::string restaurant);

	void printSides(std::string restaurant);

private:
	map<Category, vector<Menu>> theMenu;
};


#endif