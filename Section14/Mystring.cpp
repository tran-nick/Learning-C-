#include "Mystring.h"


Mystring::Mystring()
	:str{ new char[1] } {
	*str = '\0';
}

Mystring::Mystring(const char* s)
	: str{ nullptr }{
	if (s == nullptr) {
		str = new char[1];
		*str = '\0'; 
		/*if s is nullptr, make str pointer point to array size 1 
		then derefernece str pointer and assign terminator '\0' */
	}
	else {
		str = new char[std::strlen(s) + 1];
		std::strcpy(str, s);
	}
}

//copy constructor
Mystring::Mystring(const Mystring& source)
//is there problem using initialz list like this? program seems to run fine
	:str{ new char[strlen(source.str) + 1] } {
	std::strcpy(str, source.str);
	/*std::cout << "copy constructor used" << std::endl;*/
}

//move constructor
Mystring::Mystring(Mystring&& source) noexcept
	: str{ source.str }  {
	source.str = nullptr;
}
//move constructor, pass r-value reference to a Mystring 
//noexcept tells compiler this wont throw an exception
//rules of C++, if we provide move constructor or move assignment operator
//copy assignment  not generated by compiler

//when I didn't include, VS gave me Linker errors. 
//If it's protoyped in header, needs to be implemented in cpp
Mystring::~Mystring() {
	delete[] str;
};

void Mystring::display() const {
	std::cout << str << "length: " << get_length() << std::endl;
}

size_t Mystring::get_length() const {
	return std::strlen(str);
}

//return const pointer to cstyle string
const char *Mystring::get_str() const{
	return str;
}


//copy assignment
Mystring& Mystring::operator=(const Mystring& rhs) {
	//compare address if they are same\
	//return derefence pointer to Mystring if true
	if (this == &rhs) return *this;

	//otherwise clear whatever str pointer point at
	//allocate new mem, copy, dereference and return this pointer to Mystring object
	delete[]str;
	str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(str, rhs.str);
	return *this;
}


//move assignment
Mystring& Mystring::operator=(Mystring&& rhs) noexcept {
	//always need to check for self assignment
	if (this == &rhs) return *this;

	delete[] str; //clear whatever str ptr point at
	str = rhs.str; //steal pointer
	rhs.str = nullptr; //null source ptr
	return *this; //return dereference pointer to Mystring object
}



//const at end of func because we not modifying the this pointer
Mystring Mystring::operator-() const {
	//can pass in ptr to cstyle string because func will follow memory until it hits terminator \0
	char* buff = new char[std::strlen(str) + 1];
	std::strcpy(buff, str);
	for (size_t i{ 0 }; i < std::strlen(buff); i++) {
		buff[i] = std::tolower(buff[i]);
	}
	Mystring temp{ buff };
	delete[]buff;
	return temp;
}

bool Mystring::operator==(const Mystring& rhs) const {
	return (std::strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring& rhs) const {
	return !(this->operator==(rhs));
}


//strcmp return negative if lhs before rhs lexicographically
bool Mystring::operator<(const Mystring& rhs) const {
	return (std::strcmp(str, rhs.str) > 0);
}

//strcmp return positive if lhs before rhs lexicographically
bool Mystring::operator>(const Mystring& rhs) const {
	return (std::strcmp(str, rhs.str) < 0);
}


Mystring Mystring::operator+(const Mystring& rhs) const {
	char* buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
	std::strcpy(buff, str);
	std::strcat(buff, rhs.str);
	Mystring temp{ buff };
	delete[]buff;
	return temp;
}


//In some cases, we want to return an l - value.If so, the we must return a reference.
Mystring& Mystring::operator+=(const Mystring& rhs) {
	/*derefenced this pointer gives mystring object so statement evaluates to
	Mystring = Mystring + Mystring -> Mystring.operator=(Mystring.operator+(rhs))*/
	*this = *this + rhs;
	return *this;
}

Mystring Mystring::operator*(size_t times) const {
	char* buff = new char[std::strlen(str) * times + 1];
	std::strcpy(buff, str);
	for (size_t i{ 0 }; i < times - 1; i++) { //minus one because we did once with strcpy
		std::strcat(buff, str);
	}
	Mystring temp{ buff };
	delete[]buff;
	return temp;
}

Mystring& Mystring::operator*=(size_t times) {
	*this = *this * times;
	return *this;
}

//returns all uppercase
//pre-increment
Mystring& Mystring::operator++() {
	//like lowercase operator-, but using std::toupper
	for (size_t i{ 0 }; i < std::strlen(str); i++){
		str[i] = std::toupper(str[i]);
	}
	return *this;
}


Mystring Mystring::operator++(int num) {
	
	Mystring temp{ *this }; //makes a copy.
	operator++(); //calls pre-increment
	return temp;
}



std::ostream& operator<<(std::ostream& out, const Mystring& rhs) {
	out << rhs.str;
	return out;
}


//answered in lecture questions
//The compiler converst std::cin >> rhs
//to:
//operator>>(std::cin , rhs)
std::istream& operator>>(std::istream& in, Mystring& rhs) {
	char* buff = new char[1000]; //allocate mem 
	in >> buff; //get input and store it into buff
	rhs = Mystring{ buff }; //assign rhs to Mystring initialized to buff
	delete[]buff; //delete buff, no longer needed. 
	return in;
}

//notes:
//?when to use &operator vs operator?
//"The difference is how we want to return the object.
//
//In some cases, we want to return an l - value.If so, the we must return a reference.
//Type &operator should read as operator = &Type. The return type is a reference to class "Type". 


//This is the case with operator= since we want an l - value so that we can chain assignments.
//
//a = b = c;
//
//In other cases we want to return an object by value.This is the case with operators such as +
//
//a = b + c;
//
//We want to create a new object whose value is b + c and then return it so it will be assigned to a.
//We do not want to return an l - value in this case.If we did, we would be returning the l - value of b in operator+ which really doesn't make sense.
//Which one to use and when depends on the semantics we want to achieve.We generally want to preserve the semantics of how the operator is defined in C++.
//Usually the semantics follow the phrase, "Do as the ints do".We want to overload our operators to preserve the semantics and work the way ints do.
//

