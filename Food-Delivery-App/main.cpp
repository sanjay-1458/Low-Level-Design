#include <iostream>
#include "FoodDelivery.h"
using namespace std;

int main()
{
    FoodDelivery *current = new FoodDelivery();

    User *user = new User(101, "Aditya", "Delhi");
    cout << "User: " << user->getName() << " is active." << endl;

    vector<Restaurant *> restaurantList = current->searchRestaurants("Delhi");

    if (restaurantList.empty())
    {
        cout << "No restaurants found!" << endl;
        return 0;
    }
    cout << "Found Restaurants:" << endl;
    for (auto restaurant : restaurantList)
    {
        cout << " - " << restaurant->getName() << endl;
    }

    current->selectRestaurant(user, restaurantList[0]);

    cout << "Selected restaurant: " << restaurantList[0]->getName() << endl;

    current->addToCart(user, "P1");
    current->addToCart(user, "P2");

    current->printUserCart(user);

    Order *order = current->checkoutNow(user, "Delivery", new UpiPaymentStrategy("1234567890"));

    current->payForOrder(user, order);

    delete current;
    delete user;

    return 0;
}