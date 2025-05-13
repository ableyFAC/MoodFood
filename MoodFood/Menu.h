#ifndef MENU_H
#define MENU_H

#include <string>
#include "RestaurantsList.h"
#include <vector>

using namespace std;

enum class Category
{
	Appetizers,
	Dessert,
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

	private:
		std::string item;
		double price;
		Category category;
};

#endif