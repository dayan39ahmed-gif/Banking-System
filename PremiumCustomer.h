//
// Created by dayan on 4/20/2026.
//

#ifndef BANKING_SYSTEM_PREMIUMCUSTOMER_H
#define BANKING_SYSTEM_PREMIUMCUSTOMER_H

#include <string>

class PremiumCustomer : public Customer {
public:
    PremiumCustomer(std::string accountNumber, std::string password, double initialBalance);
    std::string getCustomerType() override;
    void getSpecialServices();
    void applyInterest();
private:
    double loanLimit;
};


#endif //BANKING_SYSTEM_PREMIUMCUSTOMER_H