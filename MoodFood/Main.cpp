// layout for this project

// 1) menu/home page:  asks how the user is feeling today (specific message @ a certain time)
// 2) restaurant selection: using user's mood, display restaurants with foods that fit the mood best (right now, just random & different restaurants)
// 3) food selection: user chooses a restaurant to order from, works like a typical online order (order as much as user wants until user decides to check out)

// initial vision: complete! as of 7/9/2025

// things to revamp:
// 1) possible redo of filereader.  Redo in a way that when a user selects a restaurant, it will ONLY read and create objects for that restaurant, opposed to
//      creating objects for EVERY restaurant at the beginning (better efficiency)
// 2) possible redo of data structures.  Currently, searching for restaurant names and menu item names is O(n) because I'm iterating through the whole vector
//      What can be done is rewriting those data structures from vectors to hashmaps, therefore lookup and removal will only take O(1)

#include "Interface.h"

using namespace std;

int main()
{
    
    RestaurantsList res1;

    begin(res1);
    
}