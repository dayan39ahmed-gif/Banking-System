cmake_minimum_required(VERSION 4.1)
project(Banking_System)

set(CMAKE_CXX_STANDARD 23)

add_executable(Banking_System main.cpp
        Bank.cpp
        Bank.h
        Transaction.cpp
        Transaction.h
        Account.cpp
        Account.h
        Customer.cpp
        Customer.h
        RegularCustomer.cpp
        RegularCustomer.h
        PremiumCustomer.cpp
        PremiumCustomer.h
        History.h)
