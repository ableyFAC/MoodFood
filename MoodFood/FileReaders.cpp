#include "FileReaders.h"

#include <iostream>
#include <string>
#include <iomanip>

const std::string RESTAURANTS_FILE = "restaurants_database.txt";

void createRestaurantAndMenuList(std::ifstream& restaurantFile, RestaurantsList& aRestaurantList)
{
    std::string menuFile;
    int mood = 0;
    std::string restaurant;
    double rating = 0.0;

    while (restaurantFile >> menuFile >> mood >> restaurant >> rating)
    {
        std::ifstream theMenuFile;
        theMenuFile.open(menuFile);

        if (!theMenuFile)
        {
            std::cerr << menuFile << " does NOT exist" << std::endl;
            exit(1);
        }

        std::string category;
        std::string item;
        double price = 0.0;

        MenuList aMenu;

        while (theMenuFile >> category >> item >> price)
        {
            Category newCat = aMenu.stringToEnum(category);
            aMenu.addMenuItem(newCat, Menu(newCat, item, price));
        }

        aRestaurantList.addRestaurant(mood, restaurant, rating, aMenu);

    }
}

void getFileData(RestaurantsList& aRestaurantList)
{
    std::ifstream restaurantFile;

    restaurantFile.open(RESTAURANTS_FILE);

    if (!restaurantFile)
    {
        std::cerr << RESTAURANTS_FILE << " does NOT exist" << std::endl;
        exit(1);
    }

    createRestaurantAndMenuList(restaurantFile, aRestaurantList);

    restaurantFile.close();

}

