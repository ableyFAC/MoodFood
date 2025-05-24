#include "MenuList.h"
#include <iomanip>


void MenuList::addMenuItem(Category cat, const Menu& item)
{
	theMenu[cat].push_back(item);
}

Category MenuList::convert(const string& category)
{
	if (category == "Appetizers")
	{
		return Category::Appetizers;
	}
	else if (category == "Desserts")
	{
		return Category::Desserts;
	}
	else if (category == "Drinks")
	{
		return Category::Drinks;
	}
	else if (category == "Entrees")
	{
		return Category::Entrees;
	}
	else if (category == "Sides")
	{
		return Category::Sides;
	}
	else if (category == "Specials")
	{
		return Category::Specials;
	}
	else
	{
		cerr << "Category does not exist" << endl;
	}
}