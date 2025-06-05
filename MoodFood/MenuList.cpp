#include "MenuList.h"
#include <iostream>
#include <iomanip>

using namespace std;


void MenuList::addMenuItem(Category cat, const Menu& item)
{
	theMenu[cat].push_back(item);

}

Category MenuList::stringToEnum(const string& category)
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
		return Category::Unknown;
	}
}

string MenuList::enumToString(const Category& category)
{
	if (category == Category::Appetizers)
	{
		return "Appetizers";
	}
	else if (category == Category::Desserts)
	{
		return "Desserts";
	}
	else if (category == Category::Drinks)
	{
		return "Drinks";
	}
	else if (category == Category::Entrees)
	{
		return "Entrees";
	}
	else if (category == Category::Sides)
	{
		return "Sides";
	}
	else if (category == Category::Specials)
	{
		return "Specials";
	}
	else
	{
		cerr << "Category does not exist" << endl;
		return "Unknown";
	}
}

const vector<Menu>& MenuList::getItemsInCategory(Category category) const
{
	auto it = theMenu.find(category);

	if (it != theMenu.end())
	{
		return theMenu.at(category);
	}
	else
	{
		cerr << "Category not found" << endl;
	}
}