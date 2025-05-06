#ifndef RESTAURANTS_H
#define RESTAURANTS_H

#include <string>

using namespace std;

class Restaurants
{
public:
	
	Restaurants() : restaurantName(""), restaurantRating(0.0) {}

	Restaurants(std::string newName, double newRating) : 
		restaurantName(newName), restaurantRating(newRating) {}

	std::string getRestaurantName() const;
	void setRestaurantName(std::string newName);

	double getRestaurantRating() const;
	void setRestaurantRating(double newRating);

private:
	std::string restaurantName;
	double restaurantRating;
};

// I want this part to have a multimap
// where the key is the mood and the string is the restaurant name
// I want the constructors to initialize that multimap... hmmmm

#endif