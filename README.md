Banking System

A console-based ATM and banking simulation written in C++. It is built around object-oriented design: inheritance, polymorphism, templates, operator overloading, and exception handling.

Features
Login with an account number and password
Check balance, deposit, and withdraw
Transaction history with timestamps
Change password (with confirmation)
Two customer types: Regular and Premium
Premium customers can request loans from the bank's vault
Account freeze and unfreeze support at the bank level
Input checks: negative or zero amounts, insufficient funds, wrong passwords, and frozen accounts all raise exceptions
Concepts Used
Concept	Where
Inheritance and polymorphism	RegularCustomer and PremiumCustomer derive from Customer and override getCustomerType() and getSpecialServices()
Templates	History<T> is a generic record container, used for Transaction records
Operator overloading	operator<< for Customer and Transaction
Exception handling	std::runtime_error is thrown for invalid operations and caught in the ATM loop
Encapsulation	Account holds the balance and history privately, and Customer wraps it
Composition	Bank owns customers, and Customer owns an Account
Project Structure
.
├── main.cpp               # ATM menu and program entry point
├── Bank.h / Bank.cpp      # Customer list, vault, loans, freeze/unfreeze
├── Customer.h / .cpp      # Base customer: login, password, deposit, withdraw
├── RegularCustomer.h/.cpp # Regular customer type
├── PremiumCustomer.h/.cpp # Premium customer type (interest, loan benefits)
├── Account.h / .cpp       # Balance, history, frozen state
├── Transaction.h / .cpp   # A single transaction record
├── History.h              # Generic template container for records
└── CMakeLists.txt
How to Compile and Run

With g++ (any OS):

bash
g++ -std=c++17 *.cpp -o banking
./banking          # on Windows: banking.exe

With CMake:

bash
cmake -B build
cmake --build build
./build/Banking_System
Demo Accounts

Two accounts are created in main() so you can try the program straight away:

Account Number	Password	Type	Starting Balance
Alice	Al123	Regular	5000
Bob	Bo456	Premium	10000
Example Session
Welcome to the ATM

Enter Account Number:
Alice
Enter Password: Al123
Login successful.

1. Check Balance
2. Deposit
3. Withdraw
4. Transaction History
5. Change Password
6. Request for Loan
0. Logout
Enter your choice: 1
Account Balance: 5000$
Known Limitations
Data is stored in memory only, so everything resets when the program closes
Passwords are stored as plain text
The ATM serves one login per run, and the demo accounts are hard-coded
Freeze/unfreeze and interest are implemented but not yet connected to a menu option
Future Improvements
Save accounts and transactions to files
Hash passwords
Add an admin menu for the freeze/unfreeze and vault functions
Free the dynamically allocated customers with a proper destructor
Author

Dayan Ahmed CS student, learning C++, Python, and DSA, and aiming for ML/AI work.
