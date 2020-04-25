#pragma once
#include <iostream>

class IllegalBalanceException : public std::exception{


public:
    IllegalBalanceException() {}
    ~IllegalBalanceException() {}
    virtual const char* what() const noexcept override {
        return "Illegal balance exception, balance cannot be negative number";
    }
};

