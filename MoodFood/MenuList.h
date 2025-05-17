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

private:
	map<Category, vector<Menu>> theMenu;
};


#endif