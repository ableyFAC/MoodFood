#ifndef MENU_H
#define MENU_H

#include "RestaurantsList.h"
#include <string>

using namespace std;

enum class Category
{
	Appetizers,
	Desserts,
	Drinks,
	Entrees,
	Sides,
	Specials
};

class Menu
{
	public:

		Menu(Category c, std::string newItem, double newPrice) :
			item(newItem), price(newPrice), category(c) {}

		std::string getItem();

		double getPrice();

		Category getCategory();

		void setItem(std::string newItem);

		void setPrice(double newPrice);

		void setCategory(Category c);

		std::string getCategory(Category cat);

	private:
		std::string item;
		double price;
		Category category;
};

#endif