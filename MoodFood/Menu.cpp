#include "Menu.h"

string Menu::getItem() const
{ 
	return item; 
}

double Menu::getPrice() const
{ 
	return price; 
}

Category Menu::getCategory() const
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
	return price < aMenu.price;
}