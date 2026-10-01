//
// Created by dayan on 4/19/2026.
//

#include "Bank.h"
#include "RegularCustomer.h"
#include "PremiumCustomer.h"
#include <iostream>

Bank::Bank(double vault) : vault(vault){
}

void Bank::addRegularCustomer(std::string accountNumber, std::string password, double initialBalance) {
    customers.push_back(new RegularCustomer(accountNumber, password, initialBalance));
}

void Bank::addPremiumCustomer(std::string accountNumber, std::string password, double initialBalance) {
    customers.push_back(new PremiumCustomer(accountNumber, password, initialBalance));
}

Customer* Bank::findCustomer(std::string accountNumber) {
    for (auto &customer : customers) {
        if (customer->getAccountNumber() == accountNumber) {
            return customer;
        }
    }
    throw std::runtime_error("Customer not found.");
}

void Bank::giveLoan(std::string accountNumber, double amount) {
    Customer* customer = findCustomer(accountNumber);

    if (customer == nullptr) {
        throw std::runtime_error("Customer not found.");
    }

    if (amount > vault) {
        throw std::runtime_error("Insufficient funds in the vault.");
    }
        vault -= amount;
        customer->deposit(amount);
        std::cout << "Loan of " << amount << "$ has been successfully granted" << std::endl;
}

void Bank::freezeAccount(std::string accountNumber) {
    Customer* customer = findCustomer(accountNumber);
    if (customer == nullptr) {
        throw std::runtime_error("Customer not found.");
    }
    customer->freezeAccount();
}

void Bank::unfreezeAccount(std::string accountNumber) {
    Customer* customer = findCustomer(accountNumber);
    if (customer == nullptr) {
        throw std::runtime_error("Customer not found.");
    }
    customer->unfreezeAccount();
}

void Bank::showVault() {
    std::cout << "Bank vault: " << vault << "$" << std::endl;
}
