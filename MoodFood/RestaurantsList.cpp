#include "RestaurantsList.h"
#include <iomanip>

void RestaurantsList::addRestaurant(const int& mood, const string& restaurantName, const double& restaurantRating)
{
	Restaurants tempRestaurant = Restaurants(restaurantName, restaurantRating);

	resMap->emplace(mood, tempRestaurant);

}

void RestaurantsList::displayRestaurants(const int& mood)
{
	auto range = resMap->equal_range(mood);

	for(auto i = range.first; i != range.second; ++i)
	{
		cout << "\t" << i->second.getRestaurantName() << " - ( "
			<< setprecision(2) << i->second.getRestaurantRating() 
				<< "/5 stars )" << endl;
	}
}

multimap<int, Restaurants>::iterator RestaurantsList::findRestaurant(const string& restaurant)
{
	auto begin = resMap->begin();
	auto end = resMap->end();

	auto result = find_if(begin, end,
		[restaurant](const auto& temp)
		{return temp.second.getRestaurantName() == restaurant;});

	return result;
}

void RestaurantsList::printAll()
{
	auto begin = resMap->begin();
	auto end = resMap->end();

	while (begin != end)
	{
		cout << begin->second.getRestaurantName() << " | ";
		++begin;
	}
}
