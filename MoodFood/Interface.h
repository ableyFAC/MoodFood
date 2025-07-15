#ifndef INTERFACE_H
#define INTERFACE_H

#include "RestaurantsList.h"
#include "MenuList.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void begin(RestaurantsList& aRestaurant);

void userMood(RestaurantsList& aRestaurant);

void chooseRestaurant(const int& mood, RestaurantsList& aRestaurant);

void displayMenu(multimap<int, Restaurants>::iterator& it, 
	std::string restaurant); 

void printByCategory(multimap<int, Restaurants>::iterator& it, Category category, std::string restaurant);

void order(multimap<int, Restaurants>::iterator& it, Category category, std::string restaurant);

void total();
#endif