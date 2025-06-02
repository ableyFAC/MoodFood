// layout for this project

// 1) menu/home page:  asks how the user is feeling today (specific message @ a certain time)
// 2) restaurant selection: using user's mood, display restaurants with foods that fit the mood best (right now, just random & different restaurants)
// 3) food selection: user chooses a restaurant to order from, works like a typical online order (order as much as user wants until user decides to check out)

// will probably need...

// - two separate files/ .cpp files depending on the mood chosen

#include "Interface.h"
#include "RestaurantsReader.h"

using namespace std;

int main()
{

    // testing resMap and theMenu map


    MenuList mcDonaldsMenu;
    mcDonaldsMenu.addMenuItem(Category::Appetizers, Menu(Category::Appetizers, "Fries", 1.49));
    mcDonaldsMenu.addMenuItem(Category::Entrees, Menu(Category::Entrees, "BigMac", 4.99));
    mcDonaldsMenu.addMenuItem(Category::Desserts, Menu(Category::Desserts, "ApplePie", 1.99));

    // Step 2: Create a Restaurant
    Restaurants mcd("McDonalds", 4.5, mcDonaldsMenu);

    // Step 3: Link the menu to the restaurant
    mcd.setMenuList(mcDonaldsMenu);

    // Step 4: Insert the restaurant into RestaurantsList
    RestaurantsList restaurantList;
    restaurantList.addRestaurant(1, "McDonalds", 4.5, mcDonaldsMenu);  // Assuming key = mood

    MenuList OlaMenu;
    OlaMenu.addMenuItem(Category::Appetizers, Menu(Category::Appetizers, "Nachos", 1.49));
    OlaMenu.addMenuItem(Category::Entrees, Menu(Category::Entrees, "StreetTacos", 4.99));
    OlaMenu.addMenuItem(Category::Desserts, Menu(Category::Desserts, "Flan", 1.99));

    // Step 2: Create a Restaurant
    Restaurants ola("Ola", 4.0, OlaMenu);

    // Step 3: Link the menu to the restaurant
    ola.setMenuList(OlaMenu);

    // Step 4: Insert the restaurant into RestaurantsList
    restaurantList.addRestaurant(1, "Ola", 4.0, OlaMenu);  // Assuming key = mood


    auto it = restaurantList.findRestaurant("Ola");

    if (it != restaurantList.getEndIterator())
    {
        cout << "Restaurant found and it's name is " << it->second.getRestaurantName();
        // GOOD, the restaurant exists in the map

        orderAppetizers(it);
        // IT WORKS :DDD
    }
    else
    {
        cout << "Restaurant not found.\n";
    }

    //RestaurantsList res1;
    //getRestaurantData(res1);

    //MenuList men1;

    //intro();

    //userMood(res1, men1);
    
}