// Section18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"


int main()
{
    try {
        //auto ptr1 = std::make_unique<Checking_Account>("Checking1", -100);
        auto ptr2 = std::make_shared<Savings_Account>();
        ptr2->withdraw(100);
    }
    catch (IllegalBalanceException& ex) {
        std::cerr << "You can't have a negative balance!" << std::endl;
    }
    catch (InsufficientFundsException& ex) {
        std::cerr << "You don't have enough funds!" << std::endl;
    }

    // test your code here
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}
