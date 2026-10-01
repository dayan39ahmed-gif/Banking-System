//
// Created by dayan on 4/19/2026.
//

#include "Transaction.h"
#include <ctime>
#include <ostream>

Transaction::Transaction(double amount, const std::string &type, const std::string &date) : amount(amount), type(type), date(date) {
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getType() const {
    return type;
}

std::string Transaction::getCurrentDateTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return std::to_string(ltm->tm_year + 1900) + "-" +
              std::to_string(ltm->tm_mon + 1) + "-" +
              std::to_string(ltm->tm_mday) + " " +
              std::to_string(ltm->tm_hour) + ":" +
              std::to_string(ltm->tm_min) + ":" +
              std::to_string(ltm->tm_sec);

}

std::ostream & operator<<(std::ostream &stream, const Transaction &transaction) {
    stream << "Transaction: " << transaction.getType() << ", Amount: " << transaction.getAmount() << ", Date: " << transaction.getCurrentDateTime();
    return stream;
}
