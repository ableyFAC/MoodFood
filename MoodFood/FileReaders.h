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
    // first:  CREATE THE RESTAURANTLIST MAP
    int mood = 0;
    string restaurant;
    double rating = 0.0;
    MenuList tempForNow;

    while (restaurantFile >> mood >> restaurant >> rating)
    {
        aRestaurantList.addRestaurant(mood, restaurant, rating, tempForNow);
    }

    // then:  CREATE THE MENULIST OBJECTS
    vector<string> menuDatabaseVector;
    string line;

    while (getline(menuDatabase, line))
    {
        menuDatabaseVector.push_back(line);
        // CONFIRMED VIA FOR LOOP: populates vector with all of the menus_txt
        // ex) Afters_menu.txt, Boudins_menu.txt,...
    }

    for (int i = 0; i < menuDatabaseVector.size(); ++i)
    {
        ifstream infile;
        string temp = menuDatabaseVector.at(i);
        infile.open(temp);

        string category;
        string item;
        double price = 0.0;

        MenuList aMenu; // initialized after while loop... say a MenuList was created for Afters - now connect that to the Restaurant Class

        while (infile >> category >> item >> price)
        {
            Category newCat = aMenu.stringToEnum(category);
            aMenu.addMenuItem(newCat, Menu(newCat, item, price));
        }

        // finally: CONNECT THE CORRESPONDING MENULIST OBJECT WITH RESTAURANT

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

