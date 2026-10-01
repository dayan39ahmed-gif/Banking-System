//
// Created by dayan on 4/20/2026.
//

#include "Customer.h"
#include "PremiumCustomer.h"
#include <iostream>

PremiumCustomer::PremiumCustomer(std::string accountNumber, std::string password, double initialBalance) : Customer(accountNumber, password, initialBalance) {
}

std::string PremiumCustomer::getCustomerType() {
    return "PremiumCustomer";
}

void PremiumCustomer::getSpecialServices() {
    std::cout << "You have special benefits of higher loan limit and interest" << std::endl;
}

void PremiumCustomer::applyInterest() {
    double interest = getBalance() * 0.05;
    deposit(interest);
    std::cout << "Interest Of " << interest << "$ applied" << std::endl;
}
