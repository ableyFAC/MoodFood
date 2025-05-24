#ifndef INTERFACE_H
#define INTERFACE_H

#include "RestaurantsList.h"
#include "MenuList.h"
#include <iostream>
#include <string>

using namespace std;

void intro();

void userMood(RestaurantsList& aRestaurant);

void chooseRestaurant(const int& mood, RestaurantsList& aRestaurant);

void displayMenu(RestaurantsList& aRestaurant, std::string restaurant); 

void orderAppetizers(std::string restaurant);

void orderEntrees(std::string restaurant);

void orderSpecials(std::string restaurant);

void orderDesserts(std::string restaurant);

void orderSides(std::string restaurant);

void orderDrinks(std::string restaurant);

void total();
#endif