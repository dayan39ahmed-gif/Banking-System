//
// Created by dayan on 4/19/2026.
//

#ifndef BANKING_SYSTEM_ACCOUNT_H
#define BANKING_SYSTEM_ACCOUNT_H

#include "History.h"
#include "Transaction.h"

class Account {
public:
    Account(double balance);

    double getBalance() const;

    void showBalance() const;
    void hideBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void showHistory() const;
    void freeze();
    void unfreeze();
    bool getIsFrozen() const;

private:
    double balance;
    History <Transaction> transactions;
    bool isFrozen;
};

#endif //BANKING_SYSTEM_ACCOUNT_H