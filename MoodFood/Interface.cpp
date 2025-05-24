#include "Interface.h"
#include <chrono>

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

void userMood(RestaurantsList& aRestaurant)
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

	chooseRestaurant(mood, aRestaurant);
}

void chooseRestaurant(const int& mood, RestaurantsList& aRestaurant)
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
		displayMenu(aRestaurant, selection);
	}
}

void displayMenu(RestaurantsList& aRestaurant, string restaurant)
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
				orderAppetizers(restaurant);
				break;
			case 2:
				orderEntrees(restaurant);
				break;
			case 3:
				orderSpecials(restaurant);
				break;
			case 4:
				orderDesserts(restaurant);
				break;
			case 5:
				orderSides(restaurant);
				break;
			case 6:
				orderDrinks(restaurant);
				break;
			case 7:
				total();
		}
	}
}

void orderAppetizers(string restaurant)
{
	cout << "Appetizer page";
}

void orderEntrees(string restaurant)
{
	cout << "Entrees page";
}

void orderSpecials(string restaurant)
{
	cout << "Specials page";
}

void orderDesserts(string restaurant)
{
	cout << "Desserts page";
}

void orderSides(string restaurant)
{
	cout << "Sides page";
}

void orderDrinks(string restaurant)
{
	cout << "Drinks page";
}

void total()
{
	cout << "the end" << endl;
}