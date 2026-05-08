#ifndef RESTAURANTSLIST_H
#define RESTAURANTSLIST_H

#include "Restaurants.h"
#include <map>
#include <algorithm>
#include <iostream>

// this class will handle the multimap
// int should be the mood selected
// Restaurants object holds the name and such
class RestaurantsList
{
	public:
		RestaurantsList() = default;

		RestaurantsList(const RestaurantsList& aRestaurantList);

		RestaurantsList& operator=(const RestaurantsList& aRestaurantList);

		void addRestaurant(const int& mood, const std::string& restaurantName, 
			const double& restaurantRating, const MenuList& aMenuList);

		void displayRestaurants(const int& mood);

		std::multimap<int, Restaurants>::iterator findRestaurant(const std::string& restaurant);

		auto getEndIterator() { return resMap.end(); };

		void printAll();

	private:
		std::multimap <int, Restaurants> resMap;
};

#endif