#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;

enum class Category
{
	Appetizers,
	Desserts,
	Drinks,
	Entrees,
	Sides,
	Specials,
	Unknown
};

class Menu
{
	public:

		Menu() : category(Category::Unknown), item(""), price(0.0) {}

		Menu(Category c, std::string newItem, double newPrice) :
			category(c), item(newItem), price(newPrice) {}

		std::string getItem();

		double getPrice();

		Category getCategory();

		void setItem(std::string newItem);

		void setPrice(double newPrice);

		void setCategory(Category c);

		bool operator<(const Menu& aMenu) const;

	private:
		std::string item;
		double price;
		Category category;
};

#endif