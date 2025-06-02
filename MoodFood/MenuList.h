#ifndef MENULIST_H
#define MENULIST_H

#include "Menu.h"

#include <map>
#include <vector>

using namespace std;

class MenuList
{
public:

	void addMenuItem(Category cat, const Menu& item);

	Category convert(const std::string& category);

	//void printAppetizers(multimap<int, Restaurants>::iterator&);

	//void printEntrees(std::string restaurant);

	//void printSpecials(std::string restaurant);

	//void printDrinks(std::string restaurant);

	//void printDesserts(std::string restaurant);

	//void printSides(std::string restaurant);

	const vector<Menu>& getItemsInCategory(Category category) const;

private:
	map<Category, vector<Menu>> theMenu;
};


#endif