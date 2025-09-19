/*
    maybe I can use something like this to put restaurant info into the multimap...
*/
#include "RestaurantsList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESTAURANTS_FILE = "--restaurants_database.txt";

void createRestaurantAndMenuList(ifstream& restaurantFile, RestaurantsList& aRestaurantList)
{
    string menuFile;
    int mood = 0;
    string restaurant;
    double rating = 0.0;

    while (restaurantFile >> menuFile >> mood >> restaurant >> rating)
    {
        ifstream theMenuFile;
        theMenuFile.open(menuFile);

        if (!theMenuFile)
        {
            cerr << menuFile << " does NOT exist" << endl;
            exit(1);
        }

        string category;
        string item;
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
    ifstream restaurantFile;

    restaurantFile.open(RESTAURANTS_FILE);

    if (!restaurantFile)
    {
        cerr << RESTAURANTS_FILE << " does NOT exist" << endl;
        exit(1);
    }

    createRestaurantAndMenuList(restaurantFile, aRestaurantList);

    restaurantFile.close();

}

