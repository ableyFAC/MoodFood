#include "MenuList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string MENU_FILE = "McDonalds_menu.txt";

void createRestaurantList(ifstream& infile, MenuList& aMenu)
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
}

void getRestaurantData(MenuList& aMenu)
{
    ifstream infile;

    infile.open(MENU_FILE);

    if (!infile)
    {
        cerr << MENU_FILE << " does not exist." << endl;
        exit(1);
    }

    createRestaurantList(infile, aMenu);

    infile.close();
}
