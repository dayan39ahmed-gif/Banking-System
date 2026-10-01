//
// Created by dayan on 4/19/2026.
//

#ifndef BANKING_SYSTEM_BANK_H
#define BANKING_SYSTEM_BANK_H

#include "Customer.h"
#include <vector>

class Bank {
public:
    Bank(double vault);
    void addRegularCustomer(std::string accountNumber, std::string password, double initialBalance);
    void addPremiumCustomer(std::string accountNumber, std::string password, double initialBalance);
    Customer* findCustomer(std::string accountNumber);
    void giveLoan(std::string accountNumber, double amount);
    void freezeAccount(std::string accountNumber);
    void unfreezeAccount(std::string accountNumber);
    void showVault();

private:
    double vault;
    std::vector <Customer*> customers;
};


#endif //BANKING_SYSTEM_BANK_H