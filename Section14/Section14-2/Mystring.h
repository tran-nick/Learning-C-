#pragma once
#pragma warning(disable:4996)

#include <cctype>
#include <cstring>
#include <iostream>


class Mystring
{

    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
    friend std::istream& operator>>(std::istream& in, Mystring& rhs);

	//only make friend if it needs access to private members
	//as nonmember, we no longer have this pointer referring to LHS
    friend Mystring operator-(const Mystring& obj);                                        // make lowercase
    friend Mystring operator+(const Mystring& lhs, const Mystring& rhs);       // concatenate
    friend bool operator==(const Mystring& lhs, const Mystring& rhs);           // equals
    friend bool operator!=(const Mystring& lhs, const Mystring& rhs);           // not equals
    friend bool operator<(const Mystring& lhs, const Mystring& rhs);            // less than
    friend bool operator>(const Mystring& lhs, const Mystring& rhs);            // greater than
    friend Mystring& operator+=(Mystring& lhs, const Mystring& rhs);          // s1 += s2;  concat and assign
    friend Mystring operator*(const Mystring& lhs, int n);                               // s1 = s2 * 3;  repeat s2 n times
    friend Mystring& operator*=(Mystring& lhs, int n);                                   // s1 *= 3;   s1 = s1 * 3;    
    friend Mystring& operator++(Mystring& obj);                                           // ++s1; pre-increment make uppercase
    friend Mystring operator++(Mystring& obj, int);                                        // s++; post-increment make uppercase


private:
    char* str;     
public:
    Mystring();                                                        // No-args constructor
    Mystring(const char* s);                                     // Overloaded constructor
    Mystring(const Mystring& source);                    // Copy constructor
    Mystring(Mystring&& source) noexcept;                         // Move constructor
    ~Mystring();                                                      // Destructor

    Mystring& operator=(const Mystring& rhs);     // Copy assignment
    Mystring& operator=(Mystring&& rhs) noexcept;           // Move assignment

    void display() const;

    size_t get_length() const;                                      // getters
    const char* get_str() const;

};

