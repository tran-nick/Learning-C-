#include "Account.h"

Account::Account(std::string name, double balance)
    : name{ name }, balance{ balance } {
}

//copy constructor
Account::Account(const Account&source)
    :name{source.name} , balance{source.balance}{
}

//move constructor
Account::Account(Account&& source) noexcept
    : name{ source.name }, balance{ source.balance } {
    /* Exception thrown at 0x7A5DFF80 (ucrtbased.dll) in Section15.exe: 0xC0000005
    std::string is not a pointer type; it cannot be made "null." 
    It cannot represent the absence of a value, which is what a null pointer is used to represent.
    It can be made empty, by assigning an empty string to it
    (s = "" or s = std::string()) or by clearing it(s.clear()).*/
    source.name = "";
    source.balance = 0;
}

//copy assignment
Account& Account::operator=(const Account& rhs) {
    if (this != &rhs) {
        name = rhs.name;
        balance = rhs.balance;
        return *this;
    }
    return *this;
}

//move assignment
Account& Account::operator=(Account&& rhs) noexcept {
    if (this != &rhs) {
        name = rhs.name;
        balance = rhs.balance;

        //effectively "nulling" out source object to make unusable
        rhs.name = "";
        rhs.balance = 0;
        return *this;
    }
    return *this;
}

bool Account::deposit(double amount) {
    if (amount < 0)
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
        return true;
    }
    else
        return false;
}

double Account::get_balance() const {
    return balance;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}
