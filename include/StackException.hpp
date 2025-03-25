/*
declare and define exception base and derived class for stack
*/
#ifndef STACKEXCEPTION_HPP
#define STACKEXCEPTION_HPP
#include <string>
#include <sstream>

class StackException { //base class
public:
	StackException() {}; //default constructor
	virtual ~StackException() {}; //virtual destructor
	virtual std::string GetMessage() { //virtual function to get error message with a default implementation
		std::stringstream ss;
		ss << "Stack Error Occured."; //return a generic string
		return ss.str();
	};
};

class StackEmptyException : public StackException { //derived class
public:
	StackEmptyException():StackException(){};//default constructor that calls constructor of base class
	~StackEmptyException(){}; //default destructor
	std::string GetMessage() { //function overloading
		std::string s = StackException::GetMessage(); //calls base class GetMessage
		std::stringstream ss;
		ss << s << "Stack is Empty! \n"; //add the return value from base class function call with more detail
		return ss.str(); //return a new string
	};
};

class StackFullException : public StackException { //derived class
public:
	StackFullException() :StackException() {};//default constructor that calls constructor of base class
	~StackFullException() {}; //default destructor
	std::string GetMessage() { //function overloading
		std::string s = StackException::GetMessage(); //calls base class GetMessage
		std::stringstream ss;
		ss << s << "Stack is Full! \n"; //add the return value from base class function call with more detail
		return ss.str(); //return a new string
	};
};
#endif