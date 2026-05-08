#include "RestaurantsList.h"
#include <iomanip>

RestaurantsList::RestaurantsList(const RestaurantsList& aRestaurantList) // copy constructor
{
	resMap = std::multimap<int, Restaurants>(aRestaurantList.resMap);
}

RestaurantsList& RestaurantsList::operator=(const RestaurantsList& aRestaurantList) // copy assignment operator
{
	if (this == &aRestaurantList)
	{
		std::cerr << "Attempted assignment to itself." << std::endl;
	}

	resMap = std::multimap<int, Restaurants>(aRestaurantList.resMap);
	return *this;
}

void RestaurantsList::addRestaurant(const int& mood, const std::string& restaurantName, 
	const double& restaurantRating, const MenuList& aMenuList)
{

	resMap.emplace(mood, Restaurants(restaurantName, restaurantRating, aMenuList));

}

void RestaurantsList::displayRestaurants(const int& mood)
{
	auto range = resMap.equal_range(mood);

	for(auto i = range.first; i != range.second; ++i)
	{
		std::cout << "\t" << i->second.getRestaurantName() << " - ( "
			<< std::setprecision(2) << i->second.getRestaurantRating() 
				<< "/5 stars )" << std::endl;
	}
}

std::multimap<int, Restaurants>::iterator RestaurantsList::findRestaurant(const std::string& restaurant)
{
	auto begin = resMap.begin();
	auto end = resMap.end();

	auto result = find_if(begin, end,
		[restaurant](const auto& temp)
		{return temp.second.getRestaurantName() == restaurant;});

	return result;
}

void RestaurantsList::printAll()
{
	auto begin = resMap.begin();
	auto end = resMap.end();

	while (begin != end)
	{
		std::cout << begin->second.getRestaurantName() << " | ";
		++begin;
	}
}
