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

    vector<string> menuDatabaseVector;

    string line;

    while (getline(menuDatabase, line))
    {
        menuDatabaseVector.push_back(line);
        // should populate that vector with all of the menus_txt
        // ex) Afters_menu.txt, Boudins_menu.txt,...
    }

    for (const string& file : menuDatabaseVector)
    {
        ifstream temp;
        temp.open(file);

        string category;
        string item;
        double price = 0;

        MenuList aMenu; // initialized after while loop... say a MenuList was created for Afters - now connect that to the Restaurant Class

        while (temp >> category >> item >> price)
        {

            auto newCat = aMenu.stringToEnum(category);
            aMenu.addMenuItem(newCat, Menu(newCat, item, price)); // creates a MenuList object
        }

        // use the MenuList aMenu to initialize a Restaurant Object - needs the name and rating of the restaurant


        int mood = 0;
        string restaurant;
        double rating = 0.0;


        while (restaurantFile >> mood >> restaurant >> rating)
        {
            aRestaurantList.addRestaurant(mood, restaurant, rating, aMenu);
        }

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



/*
void createMenuList(ifstream& infile, MenuList& aMenu, RestaurantsList& a)
{
    string category;
    string item;
    double price = 0;

    // just testing the mcdonalds reader

    while (infile >> category >> item >> price)
    {
        auto newCat = aMenu.convert(category);
        aMenu.addMenuItem(newCat, Menu(newCat, item, price));
    }

    auto it = a.findRestaurant("McDonalds");

    it->second.setMenuList(aMenu);
}

void getMenuData(MenuList& aMenu, RestaurantsList& a)
{
    ifstream infile;

    infile.open(MENU_FILE);

    if (!infile)
    {
        cerr << MENU_FILE << " does not exist." << endl;
        exit(1);
    }

    createMenuList(infile, aMenu, a);

    infile.close();
}

void createRestaurantList(ifstream& infile, RestaurantsList& aRestaurant)
{
    int mood = 0;
    string restaurant;
    double rating = 0.0;

    // NEXT STEP IS TO TWEAK THIS READ FILE (by adding a MenuList object)

    //while (infile >> mood >> restaurant >> rating)
    //{
        //aRestaurant.addRestaurant(mood, restaurant, rating);
    //}
}

void getRestaurantData(RestaurantsList& aRestaurant)
{
    ifstream infile;

    infile.open(RESTAURANTS_FILE);

    if (!infile)
    {
        cerr << RESTAURANTS_FILE << " does not exist." << endl;
        exit(1);
    }

    createRestaurantList(infile, aRestaurant);

    infile.close();
}
*/