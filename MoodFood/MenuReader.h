#include "MenuList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string MENU_FILE = "menuItems_database.txt";

void createRestaurantList(ifstream& infile, MenuList& aMenu)
{
    string category;
    string item;
    double price = 0;

    while (infile >> category >> item >> price)
    {
        //testing testing 
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
