#include "Restaurants.h"

string Restaurants::getRestaurantName() const
{
	return restaurantName;
}

void Restaurants::setRestaurantName(string newName)
{
	restaurantName = newName;
}

double Restaurants::getRestaurantRating() const
{
	return restaurantRating;
}

void Restaurants::setRestaurantRating(double newRating)
{
	restaurantRating = newRating;
}