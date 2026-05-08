#ifndef INTERFACE_H
#define INTERFACE_H

#include "RestaurantsList.h"
#include "MenuList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>

void begin();

void userMood();

void chooseRestaurant();

inline void displayMenu(std::multimap<int, Restaurants>::iterator& it, std::string restaurant);

void printByCategory(std::multimap<int, Restaurants>::iterator& it, Category category, std::string restaurant);

void printCart();

void editCart(std::unordered_multimap<std::string, double>& namePriceCart,
	std::multimap<int, Restaurants>::iterator& it, std::string restaurant);

void order(std::multimap<int, Restaurants>::iterator& it, Category category, std::string restaurant);

void total();


#endif