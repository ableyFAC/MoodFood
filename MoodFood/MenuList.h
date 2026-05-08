#ifndef MENULIST_H
#define MENULIST_H

#include "Menu.h"

#include <map>
#include <vector>

class MenuList
{

	public:

		void addMenuItem(Category cat, const Menu& item);

		Category stringToEnum(const std::string& category);

		std::string enumToString(const Category& category);

		const std::vector<Menu> getItemsInCategory(Category category) const;

	private:
		std::map < Category, std::vector<Menu> > theMenu;
};


#endif