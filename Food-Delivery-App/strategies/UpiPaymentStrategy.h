#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
using namespace std;

class UpiPaymentStrategy : public PaymentStrategy
{
private:
    string mobile;

public:
    UpiPaymentStrategy(const string &mob)
    {
        mobile=mob;
    }
    void pay(double amount) override
    {
        cout << "Paid amount " << amount << " using UPI;" << endl;
    }
};

#endif // UPI_PAYMENT_STRATEGY_H