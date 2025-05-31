#include "Interface.h"
#include <chrono>
#include <queue>

using namespace std;


string divider(51, '-');


void intro()
{
	cout << divider << "\n"
		<< "\t	Welcome to MoodFood!\n"
		<< divider << "\n" << endl;

	cout << "How are you feeling right now, user?\n"
		<< "\t (1) Happy :D\n"
		<< "\t (2) Doing fine :)\n"
		<< "\t (3) A little down :/\n"
		<< "\t (4) Not that great :(\n" << endl;
}

void userMood(RestaurantsList& aRestaurant, MenuList& aMenuList)
{

	int mood = 0;
	cout << "Your selection: ";
	cin >> mood;

	switch (mood)
	{
	case 1:
		cout << "We're glad to hear that! Here are some restaurants to keep the good vibes going!\n";
		break;
	case 2:
		cout << "That's good to hear! Maybe some good food can make the day even better.\n";
		break;
	case 3:
		cout << "All is well, don't worry! Let's recommend you some things to munch on!\n";
		break;
	case 4:
		cout << "We're sorry to hear that. Here are some places that can make you feel better.\n";
		break;
	default:
		cerr << "Invalid input\n";
	}
	cout << endl;

	chooseRestaurant(mood, aRestaurant, aMenuList);
}

void chooseRestaurant(const int& mood, RestaurantsList& aRestaurant, MenuList& aMenuList)
{
	aRestaurant.displayRestaurants(mood);
	cout << endl;

	bool found = false;
	string selection;

	while (!found)
	{
		cout << "Please select a restaurant: ";
		cin >> selection;

		if (aRestaurant.findRestaurant(selection))
		{
			found = true;
		}
		else
		{
			cerr << "\nRestaurant not found. Please try again." << endl;
		}
	}

	if (found)
	{
		cout << "\nSending you to " << selection << "...\n";
		cout << divider << endl;
		displayMenu(aRestaurant, selection, aMenuList);
	}
}

void displayMenu(RestaurantsList& aRestaurant, string restaurant, MenuList& aMenuList)
{
	cout << "Welcome to " << restaurant << "!\n"
		<< "What would you like to order?" << endl;

	cout << "\t (1) Appetizers\n"
		<< "\t (2) Entrees\n"
		<< "\t (3) Specials\n"
		<< "\t (4) Desserts\n"
		<< "\t (5) Sides\n"
		<< "\t (6) Drinks\n"
		<< "\t (7) Checkout\n";

	int selection = 0;

	while (selection != 7)
	{
		cin >> selection;

		switch (selection)
		{
			case 1: 
				orderAppetizers(restaurant, aMenuList);
				break;
			case 2:
				orderEntrees(restaurant, aMenuList);
				break;
			case 3:
				orderSpecials(restaurant, aMenuList);
				break;
			case 4:
				orderDesserts(restaurant, aMenuList);
				break;
			case 5:
				orderSides(restaurant, aMenuList);
				break;
			case 6:
				orderDrinks(restaurant, aMenuList);
				break;
			case 7:
				total();
		}
	}
}

void orderAppetizers(string restaurant, MenuList& aMenuList)
{
	cout << "Appetizers\n"
		<< "------------\n";

	aMenuList.printAppetizers(restaurant);


}

void orderEntrees(string restaurant, MenuList& aMenuList)
{
	cout << "Entrees page";
}

void orderSpecials(string restaurant, MenuList& aMenuList)
{
	cout << "Specials page";
}

void orderDesserts(string restaurant, MenuList& aMenuList)
{
	cout << "Desserts page";
}

void orderSides(string restaurant, MenuList& aMenuList)
{
	cout << "Sides page";
}

void orderDrinks(string restaurant, MenuList& aMenuList)
{
	cout << "Drinks page";
}

void total()
{
	cout << "the end" << endl;
}