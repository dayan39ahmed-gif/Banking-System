//
// Created by dayan on 4/20/2026.
//

#include "RegularCustomer.h"
#include <iostream>

RegularCustomer::RegularCustomer(std::string accountNumber, std::string password, double initialBalance) : Customer(accountNumber, password, initialBalance){
}

std::string RegularCustomer::getCustomerType() {
    return "RegularCustomer";
}

void RegularCustomer::getSpecialServices() {
    std::cout << "No special services available for you! Upgrade to premium!" << std::endl;
}
