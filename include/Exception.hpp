/*
declare and define exception base and derived class
*/
#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <string>
#include <sstream>

class ArrayException { //base class
public:
	ArrayException(){}; //default constructor
	virtual ~ArrayException() {}; //virtual destructor
	virtual std::string GetMessage() { //virtual function to get error message with a default implementation
		std::stringstream ss;
		ss << "Error Occured."; //return a generic string
		return ss.str();
	};
};

class OutOfBoundsException: public ArrayException{ //derived class
private:
	int m_index; //private member data
public:
	OutOfBoundsException(int idx) :ArrayException(), m_index(idx){} //constructor that takes in an int, calls constructor of base class and initializes private member data based on the int input
	~OutOfBoundsException(){}; //default destructor
	std::string GetMessage() { //function overloading
		std::string s = ArrayException::GetMessage(); //calls base class GetMessage
		std::stringstream ss;
		ss << s << " Index out of bound at index =  " << m_index << "\n"; //add the return value from base class function call with more detail
		return ss.str(); //return a new string
	};
};
#endif