#ifndef INTERFACE_H
#define INTERFACE_H

#include "RestaurantsList.h"
#include <iostream>
#include <string>

using namespace std;

void intro();

void userMood(RestaurantsList& aRestaurant);

void chooseRestaurant(const int& mood, RestaurantsList& aRestaurant);

void printMenu(RestaurantsList& aRestaurant); 


#endif