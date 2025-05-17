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

string Menu::getCategory(Category cat)
{
	switch (cat)
	{
	case Category::Appetizers: return "Entree";
	case Category::Desserts: return "Desserts";
	case Category::Drinks: return "Drinks";
	case Category::Entrees: return "Entree";
	case Category::Sides: return "Sides";
	case Category::Specials: return "Specials";

	default:
		return "Unknown category";
	}
}