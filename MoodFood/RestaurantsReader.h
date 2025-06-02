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

void createRestaurantList(ifstream& infile, RestaurantsList& aRestaurant)
{
    int mood = 0;
    string restaurant;
    double rating = 0.0;

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