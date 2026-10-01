//
// Created by dayan on 4/20/2026.
//

#ifndef BANKING_SYSTEM_REGULARCUSTOMER_H
#define BANKING_SYSTEM_REGULARCUSTOMER_H

#include <string>

#include "Customer.h"

class RegularCustomer : public Customer {
public:
    RegularCustomer(std::string accountNumber, std::string password, double initialBalance);
    std::string getCustomerType() override;
    void getSpecialServices() override;
};


#endif //BANKING_SYSTEM_REGULARCUSTOMER_H