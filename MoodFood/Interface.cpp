#include "Interface.h"
#include "FileReaders.h"
#include <unordered_map>

std::string divider(51, '-');
std::unordered_multimap<std::string, double> namePriceCart;
int MOOD = 0;
RestaurantsList aRestaurant; 

void begin()
{
	getFileData(aRestaurant);

	std::cout << divider << "\n"
		<< "\t	Welcome to MoodFood!\n"
		<< divider << "\n" << std::endl;

	std::cout << "How are you feeling right now, user?\n"
		<< "\t (1) Happy :D\n"
		<< "\t (2) Doing fine :)\n"
		<< "\t (3) A little down :/\n"
		<< "\t (4) Not that great :(\n" << std::endl;

	userMood();
}

void userMood()
{

	while (MOOD < 1 || MOOD > 4)
	{
		std::cin >> MOOD;

		switch (MOOD)
		{
			case 1:
				std::cout << "We're glad to hear that! Here are some restaurants to keep the good vibes going!\n";
				break;
			case 2:
				std::cout << "That's good to hear! Maybe some good food can make the day even better.\n";
				break;
			case 3:
				std::cout << "All is well, don't worry! Let's recommend you some things to munch on!\n";
				break;
			case 4:
				std::cout << "We're sorry to hear that. Here are some places that can make you feel better!\n";
				break;
			default:
				std::cerr << "Invalid input\n";
		
		}
		std::cout << std::endl;
	}
	
	chooseRestaurant();
}

void chooseRestaurant()
{
	aRestaurant.displayRestaurants(MOOD);
	std::cout << std::endl;

	bool found = false;
	std::string selection;

	std::multimap<int, Restaurants>::iterator restaurantIt;

	while (!found)
	{
		std::cout << "Where would you want to eat today? ";
		std::cin >> selection;

		restaurantIt = aRestaurant.findRestaurant(selection);

		if (restaurantIt != aRestaurant.getEndIterator())
		{
			found = true;
		}
		else
		{
			std::cerr << "\nRestaurant not found. Please try again." << std::endl;
		}
	}

	if (found)
	{
		std::cout << "\nSending you to " << selection << "...\n";
		std::cout << divider << std::endl;

		displayMenu(restaurantIt, selection);
	}
}

inline void displayMenu(std::multimap<int, Restaurants>::iterator& it, 
	std::string restaurant)
{
	std::cout << "Welcome to " << restaurant << "!\n"
		<< "What would you like to order?\n"
			<< "Press '<' to select another restaurant\n" << std::endl;

	std::cout << "\t (1) Appetizers\n"
		<< "\t (2) Entrees\n"
		<< "\t (3) Specials\n"
		<< "\t (4) Desserts\n"
		<< "\t (5) Sides\n"
		<< "\t (6) Drinks\n"
		<< "\t (7) Edit Cart\n"
		<< "\t (8) Checkout\n";

	char selection = '0';

	while (selection != '<')
	{
		std::cin >> selection;

		if (selection == '1')
		{
			printByCategory(it, Category::Appetizers, restaurant);
		}
		else if (selection == '2')
		{
			printByCategory(it, Category::Entrees, restaurant);
		}
		else if (selection == '3')
		{
			printByCategory(it, Category::Specials, restaurant);
		}
		else if (selection == '4')
		{
			printByCategory(it, Category::Desserts, restaurant);
		}
		else if (selection == '5')
		{
			printByCategory(it, Category::Sides, restaurant);
		}
		else if (selection == '6')
		{
			printByCategory(it, Category::Drinks, restaurant);
		}
		else if (selection == '7')
		{
			editCart(namePriceCart, it, restaurant);
		}
		else if (selection == '8')
		{
			total();
		}
	}

	if (selection == '<')
	{
		std::cout << "\nReturning you to the restaurant selection page...\n" << std::endl;
		chooseRestaurant();
	}
}

void printByCategory(std::multimap<int, Restaurants>::iterator& it, Category category, std::string restaurant)
{
	MenuList menu;

	std::string categoryName = menu.enumToString(category);
	std::cout << categoryName << "\n" << "------------ \n";

	menu = it->second.getMenuList();

	std::vector<Menu> tempVector = menu.getItemsInCategory(category); // prints "Not found" if applicable

	if (tempVector.empty())
	{
		std::cout << "Sorry!  We do not carry any " << categoryName << ". We will return you to the main page.\n" << std::endl;
		displayMenu(it, restaurant);
	}
	
	sort(tempVector.begin(), tempVector.end()); // THIS sorts based on PRICE due to the overloaded comparison operator

	for (int i = 0; i < tempVector.size(); ++i)
	{
		std::cout << "\t" << tempVector[i].getItem() << " - $"
			<< std::fixed << std::setprecision(2) << tempVector[i].getPrice() << std::endl;
	}
		
	order(it, category, restaurant);
	
}

void order(std::multimap<int, Restaurants>::iterator& it, Category category, std::string restaurant)
{
	MenuList& menu = it->second.getMenuList();
	std::vector<Menu> tempVector = menu.getItemsInCategory(category);

	std::string option;

	while (option != "n")
	{
		std::cout << "\n	Please make an order (enter 'n' when done with this category): ";

		std::cin >> option;

		if (option == "n")
		{
			return displayMenu(it, restaurant);
		}

		for(const Menu& item: tempVector)
		{
			if (item.getItem() == option)
			{
				namePriceCart.emplace(item.getItem(), item.getPrice());
				std::cout << "\t" << option << " added to cart. " << std::endl;
			}
		}
	}
}

void printCart()
{
	std::cout << "Your cart: \n" << std::endl;
	double total = 0;

	auto it = namePriceCart.begin();
	while (it != namePriceCart.end())
	{
		std::cout << "\t" << it->first << " - $" << std::fixed << std::setprecision(2) << it->second << std::endl;
		total = total + it->second;
		++it;
	}

	double tax = total * 0.0725;

	std::cout << "\tTax - $" << std::fixed << std::setprecision(2) << tax
		<< "\n\t-------------------\n"
		<< "\tTotal: $" << total + tax << std::endl;
}

void editCart(std::unordered_multimap<std::string, double>& namePriceCart,
	std::multimap<int, Restaurants>::iterator& it, std::string restaurant)
{

	std::string removeItem;

	while (removeItem != "n")
	{
		std::cout << "Which item do you want to remove? (type 'n' to exit)\n\n";

		if (namePriceCart.empty())
		{
			std::cout << "Cart is empty!  Returning you back to the previous slide" << std::endl;
			return displayMenu(it, restaurant);
		}

		printCart();
		
		std::cin >> removeItem;

		auto npIt = namePriceCart.find(removeItem);

		if (npIt != namePriceCart.end())
		{
			namePriceCart.erase(npIt);

			std::cout << removeItem << " has been removed." << std::endl;
			
		}
		else if (removeItem == "n")
		{
			return displayMenu(it, restaurant);
		}
		else
		{
			std::cout << "Item does not exist" << std::endl;
		}

	}

}

void total()
{

	printCart();

	std::cout << "\nTransferring you to payment section...\n" << std::endl;
	
	std::string cardNumber;
	cardNumber.reserve(16);

	while (cardNumber.size() != 16)
	{
		std::cout << "Please input your credit or debit card number: ";

		std::cin >> cardNumber;
		int size = static_cast<int>(cardNumber.size());
		if (size != 16)
		{
			std::cout << "Invalid card number!  Try again\n" << std::endl;
		}
	}

	std::string encrypted;

	for (unsigned int i{ 0 }; i < cardNumber.size() - 4; ++i)
	{
		encrypted += '*';

		if ((i + 1) % 4 == 0)
		{
			encrypted += '-';
		}

	}
	std::string remains = cardNumber.substr(12, cardNumber.size());
	encrypted += remains;

	std::cout << "Card number: " << encrypted << " ending in " << remains << std::endl;
	
	std::cout << "Payment accepted!  You will be updated about when you can pick up your order.  Thank you for using MoodFood!" << std::endl;
	exit(1);

}
