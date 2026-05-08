#ifndef FILEREADERS_H
#define FILEREADERS_H

#include "RestaurantsList.h"
#include <fstream>

void createRestaurantAndMenuList(std::ifstream& restaurantFile, RestaurantsList& aRestaurantList);

void getFileData(RestaurantsList& aRestaurantList);

#endif