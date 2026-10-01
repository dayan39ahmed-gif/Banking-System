//
// Created by dayan on 4/19/2026.
//

#include "Customer.h"
#include <iostream>

Customer::Customer(std::string accountNumber, std::string password, double initialBalance)
                : accountNumber(accountNumber), password(password), account(initialBalance) {
}

std::string Customer::getAccountNumber() const {
    return accountNumber;
}

std::string Customer::getPassword() const {
    return password;
}

std::string Customer::getCustomerType() {
    return "Customer";
}

void Customer::getSpecialServices() {
    std::cout << "There are no special services available!" << std::endl;
}

double Customer::getBalance() const {
    return account.getBalance();
}

void Customer::setPassword() {
    std::cout << "Enter current password: ";
    std::string pass;
    std::cin >> pass;

    if (pass == password) {
        std::cout << "Enter new password: ";
        std::string newPassword;
        std::cin >> newPassword;
        std::cout << "Confirm new password: ";
        std::string confirmPassword;
        std::cin >> confirmPassword;
        if (confirmPassword == newPassword) {
            password = newPassword;
            std::cout << "Password changed successfully." << std::endl;
        } else {
            throw std::runtime_error("Passwords do not match. Password change failed.");
        }
    }
    else {
        throw std::runtime_error("Wrong current password.");
    }
}

bool Customer::login() {
    std::cout << "Enter Password: ";
    std::string inputPassword;
    std::cin >> inputPassword;
    if (this->password == inputPassword) {
        std::cout << "Login successful." << std::endl;
        loggedIn = true;
        return true;
    }
        throw std::runtime_error("Incorrect password. Login failed.");
}

void Customer::logout() {
    if (!loggedIn) {
        std::cout << "You haven't logged in yet!" << std::endl;
        return;
    }
    std::cout << "Logged out successfully." << std::endl;
    loggedIn = false;
}

void Customer::showHistory() const {
    account.showHistory();
}

void Customer::freezeAccount() {
    account.freeze();
}

void Customer::unfreezeAccount() {
    account.unfreeze();
}

void Customer::deposit(double amount) {
    account.deposit(amount);
}

void Customer::withdraw(double amount) {
    account.withdraw(amount);
}

void Customer::showBalance() const {
    account.showBalance();
}

std::ostream & operator<<(std::ostream &stream, const Customer &customer) {
    stream << "Account Number: " << customer.getAccountNumber()
                << "\n Initial Balance: " << customer.getBalance() << std::endl << std::endl;
    return stream;
}
