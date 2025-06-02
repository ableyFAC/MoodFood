#ifndef INTERFACE_H
#define INTERFACE_H

#include "RestaurantsList.h"
#include "MenuList.h"
#include <iostream>
#include <string>

using namespace std;

void intro();

void userMood(RestaurantsList& aRestaurant, MenuList& aMenuList);

void chooseRestaurant(const int& mood, RestaurantsList& aRestaurant, MenuList& aMenuList);

void displayMenu(multimap<int, Restaurants>::iterator&, 
	std::string restaurant, MenuList& aMenuList); 

void orderAppetizers(multimap<int, Restaurants>::iterator& it);

void orderEntrees(multimap<int, Restaurants>::iterator&, MenuList& aMenuList);

void orderSpecials(std::string restaurant, MenuList& aMenuList);

void orderDesserts(std::string restaurant, MenuList& aMenuList);

void orderSides(std::string restaurant, MenuList& aMenuList);

void orderDrinks(std::string restaurant, MenuList& aMenuList);

void total();
#endif