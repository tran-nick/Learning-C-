#pragma once
#include <iostream>	

class InsufficientFundsException :public std::exception {


public:
	InsufficientFundsException() {}; //need the {} for implementation otherwise linker err LINK2019
	~InsufficientFundsException() {};
	virtual const char* what() const noexcept override {
		return "Insufficient Funds Exception - There are not enough funds in your balance";
	}
};