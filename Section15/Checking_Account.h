#pragma once
#pragma warning(disable:26439)

#include "Account.h"
#include <iostream>
#include <string>


class Checking_Account: public Account
{
	friend std::ostream& operator<<(std::ostream& out, const Checking_Account& source);

private:
	static constexpr double wdraw_fee = 1.50;
	static constexpr double def_balance = 0.0;
	static constexpr const char* def_name = "Unnamed Checking Account";

public:
	Checking_Account(); //no args
	Checking_Account(std::string name = def_name, double balance = def_balance); //default

	Checking_Account(const Checking_Account& source); //copy const
	Checking_Account(Checking_Account&& source) noexcept; //move const
	
	
	bool withdraw(double amount);
	//inherit deposit(double amount)
	//inherit get_balance();

	Checking_Account& operator=(const Checking_Account& rhs); //copy assign
	Checking_Account& operator=(Checking_Account&& rhs) noexcept; //move assign
};

