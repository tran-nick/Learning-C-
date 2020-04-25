#pragma once
#include <iostream>
#include <string>
#include "I_Printable.h"

class Account : public I_Printable{
    
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    //abstract class can't be instantiated, but can still have constructor
    //so that concrete classes that inherit can utilize
    Account(std::string name = def_name, double balance = def_balance);
    virtual ~Account() = default;
    virtual bool deposit(double amount) = 0; //=0, pure virtual function
    virtual bool withdraw(double amount) = 0;

    /*=0 means derived classes must provide implmentation, but doesnt mean
    base class cannot provide an implementation. Advantage is that it can provide
    default behavior or additive implementation*/

    virtual void print(std::ostream& out) const override;
};
