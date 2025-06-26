#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Cart.h"
using namespace std;

class User
{
private:
    int userId;
    string name;
    string address;
    Cart* cart;
public:
    User(int userId,const string&name,const string&address){
        this->userId=userId;
        this->name=name;
        this->address=address;
        cart=new Cart();
    }
    ~User(){
        delete cart;
    }
    string getName() const{
        return name;
    }
    string setName(const string&name) {
        this->name=name;
    }
    string getAddress() const{
        return address;
    }
    string setAddress(const string&address) {
        this->address=address;
    }
    Cart* getCart() const{
        return cart;
    }
};


#endif // USER_H