#pragma once
#include <vector>
#include <iostream>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"


// Utility helper functions for Account class

void display(const std::vector<Account*>& accounts);
void deposit(std::vector<Account*>& accounts, double amount);
void withdraw(std::vector<Account*>& accounts, double amount);;


