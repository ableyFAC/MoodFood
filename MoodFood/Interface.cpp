#include "Interface.h"
#include "FileReaders.h"
#include <unordered_map>

using namespace std;

string divider(51, '-');
unordered_multimap<string, double> namePriceCart;

void begin(RestaurantsList& aRestaurant)
{
	getFileData(aRestaurant);

	cout << divider << "\n"
		<< "\t	Welcome to MoodFood!\n"
		<< divider << "\n" << endl;

	cout << "How are you feeling right now, user?\n"
		<< "\t (1) Happy :D\n"
		<< "\t (2) Doing fine :)\n"
		<< "\t (3) A little down :/\n"
		<< "\t (4) Not that great :(\n" << endl;

	userMood(aRestaurant);
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
		cout << "We're sorry to hear that. Here are some places that can make you feel better!\n";
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

	multimap<int, Restaurants>::iterator restaurantIt;

	while (!found)
	{
		cout << "Where would you want to eat today? ";
		cin >> selection;

		restaurantIt = aRestaurant.findRestaurant(selection);

		if (restaurantIt != aRestaurant.getEndIterator())
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

		displayMenu(restaurantIt, selection);
	}
}

void displayMenu(multimap<int, Restaurants>::iterator& it, 
	string restaurant)
{

	cout << "Welcome to " << restaurant << "!\n"
		<< "What would you like to order?\n" << endl;

	cout << "\t (1) Appetizers\n"
		<< "\t (2) Entrees\n"
		<< "\t (3) Specials\n"
		<< "\t (4) Desserts\n"
		<< "\t (5) Sides\n"
		<< "\t (6) Drinks\n"
		<< "\t (7) Edit Cart\n"
		<< "\t (8) Checkout\n";

	int selection = 0;

	while (selection != 8)
	{
		cin >> selection;

		if (selection == 1)
		{
			printByCategory(it, Category::Appetizers, restaurant);
		}
		else if (selection == 2)
		{
			printByCategory(it, Category::Entrees, restaurant);
		}
		else if (selection == 3)
		{
			printByCategory(it, Category::Specials, restaurant);
		}
		else if (selection == 4)
		{
			printByCategory(it, Category::Desserts, restaurant);
		}
		else if (selection == 5)
		{
			printByCategory(it, Category::Sides, restaurant);
		}
		else if (selection == 6)
		{
			printByCategory(it, Category::Drinks, restaurant);
		}
		else if (selection == 7)
		{
			editCart(namePriceCart, it, restaurant);
		}
	}

	if (selection == 8)
	{
		total();
	}
}

void printByCategory(multimap<int, Restaurants>::iterator& it, Category category, string restaurant)
{
	MenuList menu;

	string categoryName = menu.enumToString(category);
	cout << categoryName << "\n" << "------------ \n";

	menu = it->second.getMenuList();

	vector<Menu> tempVector = menu.getItemsInCategory(category); // prints "Not found" if applicable

	if (tempVector.empty())
	{
		cout << "Sorry!  We do not carry any " << categoryName << ". We will return you to the main page.\n" << endl;
		return displayMenu(it, restaurant);
	}
	
	sort(tempVector.begin(), tempVector.end()); // THIS sorts based on PRICE due to the overloaded comparison operator

	for (int i = 0; i < tempVector.size(); ++i)
	{
		cout << "\t" << tempVector[i].getItem() << " - $"
			<< fixed << setprecision(2) << tempVector[i].getPrice() << endl;
	}
		
	order(it, category, restaurant);
	
}

void order(multimap<int, Restaurants>::iterator& it, Category category, string restaurant)
{
	MenuList& menu = it->second.getMenuList();
	vector<Menu> tempVector = menu.getItemsInCategory(category);

	string option;

	while (option != "n")
	{
		cout << "\n	Please make an order (enter 'n' when done with this category): ";

		cin >> option;

		if (option == "n")
		{
			return displayMenu(it, restaurant);
		}

		for(const Menu& item: tempVector)
		{
			if (item.getItem() == option)
			{
				namePriceCart.emplace(item.getItem(), item.getPrice());
				cout << "\t" << option << " added to cart. " << endl;
			}
		}
	}
}

void printCart()
{
	cout << "Your cart: \n" << endl;
	double total = 0;

	auto it = namePriceCart.begin();
	while (it != namePriceCart.end())
	{
		cout << "\t" << it->first << " - $" << fixed << setprecision(2) << it->second << endl;
		total = total + it->second;
		++it;
	}

	double tax = total * 0.0725;

	cout << "\tTax - $" << fixed << setprecision(2) << tax
		<< "\n\t-------------------\n"
		<< "\tTotal: $" << total + tax << endl;
}

void editCart(unordered_multimap<std::string, double>& namePriceCart,
	multimap<int, Restaurants>::iterator& it, std::string restaurant)
{

	string removeItem;

	while (removeItem != "n")
	{
		cout << "Which item do you want to remove? (type 'n' to exit)\n\n";

		if (namePriceCart.empty())
		{
			cout << "Cart is empty!  Returning you back to the previous slide" << endl;
			return displayMenu(it, restaurant);
		}

		printCart();
		
		cin >> removeItem;

		auto npIt = namePriceCart.find(removeItem);

		if (npIt != namePriceCart.end())
		{
			namePriceCart.erase(npIt);

			cout << removeItem << " has been removed." << endl;
			
		}
		else if (removeItem == "n")
		{
			return displayMenu(it, restaurant);
		}
		else
		{
			cout << "Item does not exist" << endl;
		}

	}

}

void total()
{

	printCart();

	cout << "\nTransferring you to payment section...\n" << endl;
	
	string cardNumber;
	cardNumber.reserve(16);

	while (cardNumber.size() != 16)
	{
		cout << "Please input your credit or debit card number: ";

		cin >> cardNumber;
		int size = cardNumber.size();
		if (size != 16)
		{
			cout << "Invalid card number!  Try again\n" << endl;
		}
	}

	string encrypted;

	for (int i = 0; i < cardNumber.size() - 4; ++i)
	{
		encrypted += '*';

		if ((i + 1) % 4 == 0)
		{
			encrypted += '-';
		}

	}
	string remains = cardNumber.substr(12, cardNumber.size());
	encrypted += remains;

	cout << "Card number: " << encrypted << " ending in " << remains << endl;

	cout << "Payment accepted!  You will be updated about when you can pick up your order.  Thank you for using MoodFood!" << endl;
	exit(1);

}
