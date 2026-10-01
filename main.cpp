
#include "Bank.h"
#include "Customer.h"
#include <iostream>

void runATM (Bank& bank) {
    std::cout << "Welcome to the ATM\n" << std::endl;
    std::cout << "Enter Account Number: " << std::endl;
    std::string accountNumber;
    std::cin >> accountNumber;
        try {
            Customer* customer = bank.findCustomer(accountNumber);
            customer->login();

            int choice;
            do {
                std::cout << "\n1. Check Balance" << std::endl;
                std::cout << "2. Deposit" << std::endl;
                std::cout << "3. Withdraw" << std::endl;
                std::cout << "4. Transaction History" << std::endl;
                std::cout << "5. Change Password" << std::endl;
                std::cout << "6. Request for Loan" << std::endl;
                std::cout << "0. Logout" << std::endl;
                std::cout << "Enter your choice: ";

                std::cin >> choice;

                switch (choice) {
                    case 1:
                        customer->showBalance();
                        break;
                    case 2:
                        std::cout << "Enter amount to deposit: ";
                        double depAmount;
                        std::cin >> depAmount;
                        customer->deposit(depAmount);
                        break;
                    case 3:
                        std::cout << "Enter amount to withdraw: ";
                        double withAmount;
                        std::cin >> withAmount;
                        customer->withdraw(withAmount);
                        break;

                    case 4:
                        customer->showHistory();
                        break;

                    case 5:
                        customer->setPassword();
                        break;

                    case 6:
                        if (customer->getCustomerType() == "PremiumCustomer") {
                            std::cout << "Enter loan amount: ";
                            double loanAmount;
                            std::cin >> loanAmount;
                            bank.giveLoan(accountNumber, loanAmount);
                        } else {
                            std::cout << "Loan requests are only available for Premium customers." << std::endl;
                        }
                        break;

                    case 0:
                        customer->logout();
                        return;

                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                }
            } while (true);
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
}

int main() {
    Bank bank(100000000);
    bank.addRegularCustomer("Alice", "Al123", 5000);
    bank.addPremiumCustomer("Bob", "Bo456", 10000);
    runATM(bank);
    return 0;
}