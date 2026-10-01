//
// Created by dayan on 4/19/2026.
//

#include "Account.h"

#include <iostream>

Account::Account(double balance) : balance(balance), isFrozen(false){
}

double Account::getBalance() const {
    return balance;
}

void Account::showBalance() const {
    std::cout << "Account Balance: " << getBalance() << "$" << std::endl;
}

void Account::hideBalance() const {
    std::cout << "Account Balance: " << "*****" << std::endl;
}

void Account::deposit(double amount) {
    if (isFrozen ==true) {
        throw std::runtime_error("Your account has been frozen!");
    }

    if (amount <= 0) {
        throw std::runtime_error("Amount must be greater than zero.");
    }

    balance += amount;
    transactions.addRecord(Transaction(amount, "Deposit", Transaction::getCurrentDateTime()));
}

void Account::withdraw(double amount) {
    if (isFrozen ==true) {
        throw std::runtime_error("Your account has been frozen!");
    }

    if (amount <= 0) {
        throw std::runtime_error("Amount must be greater than zero.");
    }

    if (amount > balance) {
        throw std::runtime_error("Insufficient funds!");
    }
        balance -= amount;
        transactions.addRecord(Transaction(amount, "Withdraw", Transaction::getCurrentDateTime()));
}

void Account::showHistory() const {
        transactions.showRecords();
}

void Account::freeze() {
    isFrozen = true;
}

void Account::unfreeze() {
    isFrozen = false;
}

bool Account::getIsFrozen() const {
    return isFrozen;
}
