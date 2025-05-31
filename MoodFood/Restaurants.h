#ifndef RESTAURANTS_H
#define RESTAURANTS_H

#include "Menu.h"
#include <string>

using namespace std;

class Restaurants
{
public:
	
	Restaurants() : restaurantName(""), restaurantRating(0.0),
		restaurantsMenu(nullptr) {}

	Restaurants(std::string newName, double newRating, Menu* newMenu) : 
		restaurantName(newName), restaurantRating(newRating), 
			restaurantsMenu(newMenu) {}

	std::string getRestaurantName() const;
	void setRestaurantName(std::string newName);

	double getRestaurantRating() const;
	void setRestaurantRating(double newRating);

	bool operator<(const Restaurants& aRestaurant) const;

private:
	std::string restaurantName;
	double restaurantRating;
	Menu* restaurantsMenu;
};

#endif