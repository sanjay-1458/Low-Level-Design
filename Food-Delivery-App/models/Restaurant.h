#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include <vector>
#include "MenuItem.h"
using namespace std;

class Restaurant
{
private:
    static int nextRestaurantId;
    int restaurantId;
    string name;
    string location;
    vector<MenuItem> menu;

public:
    Restaurant(const string &name, const string &location)
    {
        this->name = name;
        this->location = location;
        this->restaurantId = ++nextRestaurantId;
    }
    ~Restaurant()=default;

    // const promise that no chnages will be made to the member variable
    string getName() const
    {
        return name;
    }
    void setName(const string &name)
    {
        this->name = name;
    }
    string getLocation() const
    {
        return location;
    }
    void setLocation(const string &location)
    {
        this->location = location;
    }
    void addMenuItem(const MenuItem &item)
    {
        menu.push_back(item);
    }
    // const at first tells that we cant modify the refernce we recived
    const vector<MenuItem> &getMenu() const
    {
        return menu;
    }
};

int Restaurant::nextRestaurantId = 0;

#endif // RESTAURANT_H
