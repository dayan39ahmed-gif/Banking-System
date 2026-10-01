//
// Created by dayan on 4/19/2026.
//

#ifndef BANKING_SYSTEM_TRANSACTION_H
#define BANKING_SYSTEM_TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(double amount, const std::string& type, const std::string& date);

    double getAmount() const;
    std::string getType() const;
    static std::string getCurrentDateTime();

private:
    double amount;
    std::string type;
    std::string date;
};

std::ostream& operator<<(std::ostream& os, const Transaction& transaction);

#endif //BANKING_SYSTEM_TRANSACTION_H