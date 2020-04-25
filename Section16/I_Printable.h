#pragma once
#include <iostream>

class I_Printable
{
	friend std::ostream& operator<<(std::ostream& out, const I_Printable& obj);

public:
	virtual void print(std::ostream& out) const = 0;
	virtual ~I_Printable() = default; //explicit telling default compiler destructor action

};

