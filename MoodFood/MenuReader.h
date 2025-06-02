#include "MenuList.h"
#include "RestaurantsList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string MENU_FILE = "McDonalds_menu.txt";

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
