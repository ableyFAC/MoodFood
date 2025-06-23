#ifndef RESTAURANTSLIST_H
#define RESTAURANTSLIST_H

#include "Restaurants.h"
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
// this class will handle the multimap
// int should be the mood selected
// Restaurants object holds the name and such
class RestaurantsList
{
	friend class MenuList;
public:
	RestaurantsList() : resMap(new multimap<int, Restaurants>) {};

	void addRestaurant(const int& mood, const std::string& restaurantName, 
		const double& restaurantRating, const MenuList& aMenuList);

	void displayRestaurants(const int& mood);

	multimap<int, Restaurants>::iterator findRestaurant(const std::string& restaurant);

	auto getEndIterator() {
		return resMap->end();
	};

	void printAll();

	~RestaurantsList();

private:
	std::multimap <int, Restaurants>* resMap;
};

#endif