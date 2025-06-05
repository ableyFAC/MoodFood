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

	Category stringToEnum(const std::string& category);

	std::string enumToString(const Category& category);

	const vector<Menu>& getItemsInCategory(Category category) const;

private:
	map<Category, vector<Menu>> theMenu;
};


#endif