#pragma once
#pragma warning(disable:26439)
#include "Savings_Account.h"
#include <iostream>


class Trust_Account : public Savings_Account {

	friend std::ostream& operator<<(std::ostream& out, const Trust_Account& source);

private:
	static constexpr const char* def_name = "Unnamed Trust Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;
	static constexpr size_t def_wdraw_count = 0;
protected:
	size_t wdraw_count;

public:
	Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
	Trust_Account(const Trust_Account& source); //copy constr
	Trust_Account(Trust_Account&& source); //move constr

	Trust_Account& operator=(const Trust_Account& rhs); //copy assignment
	Trust_Account& operator=(Trust_Account&& rhs); //move assignment

	bool deposit(double amount);
	bool withdraw(double amount);
};