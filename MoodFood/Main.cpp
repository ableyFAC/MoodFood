// layout for this project

// 1) menu/home page:  asks how the user is feeling today (specific message @ a certain time)
// 2) restaurant selection: using user's mood, display restaurants with foods that fit the mood best (right now, just random & different restaurants)
// 3) food selection: user chooses a restaurant to order from, works like a typical online order (order as much as user wants until user decides to check out)

// will probably need...

// - two separate files/ .cpp files depending on the mood chosen

#include "Interface.h"
#include "RestaurantsReader.h"

using namespace std;

int main()
{
    RestaurantsList res1;
    getRestaurantData(res1);

    intro();

    userMood(res1);
    
}