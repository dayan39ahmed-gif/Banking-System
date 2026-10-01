//
// Created by dayan on 4/19/2026.
//

#ifndef BANKING_SYSTEM_CUSTOMER_H
#define BANKING_SYSTEM_CUSTOMER_H

#include "Account.h"
#include <string>

class Customer {
public:
    Customer(std::string accountNumber, std::string password, double initialBalance);

    std::string getAccountNumber() const;
    std::string getPassword() const;
    virtual std::string getCustomerType();
    virtual void getSpecialServices();
    double getBalance() const;
    void setPassword();

    bool login ();
    void logout();
    void showHistory() const;
    void freezeAccount();
    void unfreezeAccount();
    void deposit(double amount);
    void withdraw(double amount);
    void showBalance() const;



private:
    std::string accountNumber;
    std::string password;
    Account account;
    bool loggedIn = false;

    friend std::ostream& operator<<(std::ostream& stream, const Customer& customer);
};

#endif //BANKING_SYSTEM_CUSTOMER_H