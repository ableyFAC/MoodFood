#include "Menu.h"

string Menu::getItem()
{ 
	return item; 
}

double Menu::getPrice()
{ 
	return price; 
}

Category Menu::getCategory()
{
	return category;
}

void Menu::setItem(string newItem) 
{ 
	item = newItem; 
}

void Menu::setPrice(double newPrice) 
{ 
	price = newPrice; 
}

void Menu::setCategory(Category c)
{
	category = c;
}

bool Menu::operator<(const Menu& aMenu) const
{
	return item < aMenu.item;
}