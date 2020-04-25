#pragma once
#pragma warning(disable:4996)

#include <cctype>
#include <cstring>
#include <iostream>


class Mystring
{

	friend std::ostream& operator<<(std::ostream& out, const Mystring& rhs);
	friend std::istream& operator>>(std::istream& in, const Mystring& rhs);

private:
	//pointer to c-style string
	char* str;

public:
	Mystring(); //no args construct
	Mystring(const char* s); //overload construct
	Mystring(const Mystring& source); //copy constructor, pass l-value reference to a Mystring
	Mystring(Mystring&& source) noexcept; 	//move constructor, pass r-value reference to a Mystring 
	~Mystring(); //destructor

	Mystring& operator=(const Mystring& rhs);//copy assignment, pass l-reference
	Mystring& operator=( Mystring&& rhs) noexcept;//move assignment, pass r-refernece

	void display() const;
	size_t get_length() const;
	const char* get_str() const;

	//overloading operators as member methods
		
	/*	- turns lowercase
		== equality
		!= not equality
		< check string lexically (alphabet order)
		>
		+ concat
		+= 
		* string copied n times
		*=
		++ post / ++pre  do whatever you want
	*/ 

	Mystring operator-() const; 
	bool operator==(const Mystring& rhs) const;
	bool operator!=(const Mystring& rhs) const;
	bool operator<(const Mystring& rhs) const;
	bool operator>(const Mystring& rhs) const;
	Mystring operator+(const Mystring& rhs) const; //const because doesn't change parameter
	Mystring &operator+=(const Mystring& rhs) ;
	Mystring operator*(size_t times) const;
	Mystring &operator*=(size_t times) ;


	Mystring& operator++(); //pre-increment by reference
	Mystring operator++(int num); //return Mystring by value


};

