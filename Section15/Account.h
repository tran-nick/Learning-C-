#pragma once
#pragma warning(disable:26439)


#include <iostream>
#include <string>

class Account {
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
private:
    static constexpr const char* def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);
    // Account(std::string name = "Unamed Account", double balance = 0.0);

    Account(const Account& source); //copy constructor
    Account(Account&& source) noexcept; //move constructor
    Account& operator=(const Account& rhs); //copy assignment
    Account& operator=(Account&& rhs) noexcept; //move assignment



    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};
