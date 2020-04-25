#pragma once

#include <iostream>

class FileNotFoundException : public std::exception {

public:
	FileNotFoundException() noexcept {};
	~FileNotFoundException() = default;
	virtual const char* what() const noexcept override {
		return "Problem opening file - file not found!";
	}


};