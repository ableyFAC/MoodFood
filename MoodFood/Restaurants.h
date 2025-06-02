#ifndef RESTAURANTS_H
#define RESTAURANTS_H

#include "MenuList.h"
#include <string>

using namespace std;

class Restaurants
{
public:
	
	Restaurants() : restaurantName(""), restaurantRating(0.0),
		restaurantsMenu() {} 

	Restaurants(std::string newName, const double& newRating, const MenuList& newMenu) : 
		restaurantName(newName), restaurantRating(newRating), 
			restaurantsMenu(newMenu) {}

	std::string getRestaurantName() const;
	void setRestaurantName(std::string newName);

	double getRestaurantRating() const;
	void setRestaurantRating(double newRating);

	MenuList& getMenuList();

	void setMenuList(MenuList& menu);

	bool operator<(const Restaurants& aRestaurant) const;

private:
	std::string restaurantName;
	double restaurantRating;
	MenuList restaurantsMenu;
};

#endif