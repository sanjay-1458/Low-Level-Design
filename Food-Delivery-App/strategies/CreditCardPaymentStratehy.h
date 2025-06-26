#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
using namespace std;

class CreditCardPaymentStrategy : public PaymentStrategy
{
private:
    string cardNumber;

public:
    CreditCardPaymentStrategy(const string &card)
    {
        cardNumber = card;
    }
    void pay(double amount) override
    {
        cout << "Paid amount " << amount << " using credit card;" << endl;
    }
};

#endif // CREDIT_CARD_PAYMENT_STRATEGY_H