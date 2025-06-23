#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../models/Restaurant.h"
using namespace std;

class RestaurantManager
{
private:
    vector<Restaurant *> restaurants;
    static RestaurantManager *instance;
    RestaurantManager()
    {
    }
    RestaurantManager(const RestaurantManager &) = delete;
    RestaurantManager &operator=(const RestaurantManager &) = delete;

public:
    static RestaurantManager *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new RestaurantManager;
        }
        return instance;
    }
    void addRestaurant(Restaurant *res)
    {
        restaurants.push_back(res);
    }
    vector<Restaurant *> searchByLocation(string loc) const
    {
        vector<Restaurant *> result;
        transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
        for (auto &r : restaurants)
        {
            string curr = r->getLocation();
            transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
            if (curr == loc)
            {
                result.push_back(r);
            }
        }
        return result;
    }
};
RestaurantManager *RestaurantManager::instance = nullptr;

#endif // RESTAURANTMANAGER_H