#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
	: Savings_Account{ name, balance, int_rate } , wdraw_count{ 0 } {
}

//copy constr
Trust_Account::Trust_Account(const Trust_Account& source) 
	: Savings_Account{name , balance , int_rate} , wdraw_count{ wdraw_count } {
}

//move constr
Trust_Account::Trust_Account(Trust_Account&& source) 
	: Savings_Account{ source.name , source.balance , source.int_rate }, wdraw_count{ source.wdraw_count } {
		source.name = "";
		source.balance = 0;
		source.int_rate = 0;
		source.wdraw_count = 0;
}

//copy assignment
Trust_Account& Trust_Account::operator=(const Trust_Account& rhs) {
	if (this != &rhs) {
		Savings_Account::operator=(rhs);
		wdraw_count = rhs.wdraw_count;
		return *this;
	}
	return *this;
}

//move assignment
Trust_Account& Trust_Account::operator=(Trust_Account&& rhs) {
	if (this != &rhs) {
		Savings_Account::operator=(rhs);
		wdraw_count = rhs.wdraw_count;

		rhs.name = "";
		rhs.balance = 0;
		rhs.int_rate = 0;
		rhs.wdraw_count = 0;
		return *this;
	}
	return *this;
}

bool Trust_Account::deposit(double amount) {
	if (amount >= 5000) amount += 50;
	return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
	double wdraw_limit = balance * 0.20;
	if (wdraw_count < 3 || amount > wdraw_limit) {
		return false;
	}
	else {
		wdraw_count++;
		return Savings_Account::withdraw(amount);
	}
}

std::ostream& operator<<(std::ostream& out, const Trust_Account& account) {
	out << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << ", " << account.wdraw_count << "]";
	return out;
}