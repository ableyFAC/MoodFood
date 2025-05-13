#ifndef RESTAURANTS_H
#define RESTAURANTS_H

#include <string>
#include <map>
#include <vector>

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

private:
	std::string item;
	double price;
	Category category;
};

class Restaurants
{
public:
	
	Restaurants() : restaurantName(""), restaurantRating(0.0) {}

	Restaurants(std::string newName, double newRating) : 
		restaurantName(newName), restaurantRating(newRating) {}

	std::string getRestaurantName() const;
	void setRestaurantName(std::string newName);

	double getRestaurantRating() const;
	void setRestaurantRating(double newRating);

	void addMenuItem(Category cat, const Menu& item);
	std::string getCategory(Category cat);

private:
	std::string restaurantName;
	double restaurantRating;
	map<Category, vector<Menu>> theMenu;


};

#endif