#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
	: Account{ name, balance }{}


//copy const
Checking_Account::Checking_Account(const Checking_Account& source) 
	: Account{ source } {
}

//move const
Checking_Account::Checking_Account(Checking_Account&&source) noexcept
	: Account{ source } {
	//effectively "nulling" out source object to make unusable
	source.name = "";
	source.balance = 0;
}


//copy assignment
Checking_Account &Checking_Account::operator=(const Checking_Account& rhs) {
	if (this != &rhs) {
		Account::operator=(rhs);
		return *this;
	}
	return *this;
}

//move assignment
Checking_Account& Checking_Account::operator=(Checking_Account&& rhs) noexcept {
	if (this != &rhs) {
		Account::operator=(rhs);
		
		rhs.name = "";
		rhs.balance = 0;
		return *this;
	}
	return *this;
}


bool Checking_Account::withdraw(double amount) {
	amount += wdraw_fee;
	return Account::withdraw(amount);
}


std::ostream& operator<<(std::ostream& out, const Checking_Account& account) {
	out << "[Checking_Account: " << account.name << ": " << account.balance << ", " << "]";
	return out;
}