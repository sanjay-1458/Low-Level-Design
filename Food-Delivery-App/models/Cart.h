#ifndef CART_H
#define CART_H

#include<iostream>
#include<vector>
#include<string>

#include "../managers/RestaurantManager.h"
#include "MenuItem.h"

class Cart{
public:
    Restaurant* restaurant;
    vector<MenuItem> items;
public:
    Cart(){
        restaurant=nullptr;
    }
    void addItem(const MenuItem&item){
        if(!restaurant){
            cerr<<"Cart: Set a restaurant before adding items."<<endl;
            return;
        }
        items.push_back(item);
    }
    double getTotalCost() const{
        double sum=0;
        for(const auto&it:items){
            sum+=it.getPrice();
        }
        return sum;
    }
    bool isEmpty(){
        return (!restaurant || items.empty());
    }
    void clear(){
        items.clear();
        restaurant=nullptr;
    }
    void setRestaurant(Restaurant*r){
        restaurant=r;
    }
    Restaurant*getRestaurant() const{
        return restaurant;
    }
    const vector<MenuItem>&getItem() const{
        return items;
    }

};

#endif // CART_H