#pragma once
#include <iostream>

class NoFileFoundException : public std::exception {


public:
	NoFileFoundException() noexcept {};
	~NoFileFoundException() = default;
	virtual const char* what() const noexcept override {
		return "Problem opening file - File not found!";
	}
};