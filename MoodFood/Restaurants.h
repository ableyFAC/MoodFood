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

	bool operator<(const Restaurants& aRestaurant) const;

private:
	std::string restaurantName;
	double restaurantRating;
};

#endif