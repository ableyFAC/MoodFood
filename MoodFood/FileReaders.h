/*
    maybe I can use something like this to put restaurant info into the multimap...
*/
#include "RestaurantsList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESTAURANTS_FILE = "restaurants_database.txt";
const string MENU_DATABASE = "menu_database.txt";

void createRestaurantAndMenuList(ifstream& restaurantFile, ifstream& menuDatabase, RestaurantsList& aRestaurantList)
{
    int mood = 0;
    string restaurant;
    double rating = 0.0;
    MenuList tempForNow;

    while (restaurantFile >> mood >> restaurant >> rating)
    {
        aRestaurantList.addRestaurant(mood, restaurant, rating, tempForNow);
    }

    vector<string> menuDatabaseVector;
    string line;

    while (getline(menuDatabase, line))
    {
        menuDatabaseVector.push_back(line);
    }

    for (int i = 0; i < menuDatabaseVector.size(); ++i)
    {
        ifstream infile;
        string temp = menuDatabaseVector.at(i);
        infile.open(temp);

        string category;
        string item;
        double price = 0.0;

        MenuList aMenu;

        while (infile >> category >> item >> price)
        {
            Category newCat = aMenu.stringToEnum(category);
            aMenu.addMenuItem(newCat, Menu(newCat, item, price));
        }

        string restaurantName = temp.substr(0, temp.find("_"));

        auto it = aRestaurantList.findRestaurant(restaurantName);

        it->second.setMenuList(aMenu);
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

    ifstream menuDatabase;

    menuDatabase.open(MENU_DATABASE);

    if (!menuDatabase)
    {
        cerr << MENU_DATABASE << " does NOT exist" << endl;
        exit(1);
    }


    createRestaurantAndMenuList(restaurantFile, menuDatabase, aRestaurantList);

    restaurantFile.close();
    menuDatabase.close();

}

