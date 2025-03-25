/*
declare class Stack

*/
#ifndef STACK_HPP
#define STACK_HPP
#include "Array.hpp"
#include "StackException.hpp"

template <typename T, int size>
class Stack { //declare class
private:
	Array<T> m_array; //member data - an array of type T
	int m_current; //member data - current index
public:
	Stack(); //default constructor
	Stack(const Stack<T, size>& source); //copy constructor
	~Stack(); //destructor
	Stack<T, size>& operator =(const Stack<T, size>& source); //assignment operator
	void Push(const T& item); //Push function, add new item to the stack
	T Pop(); //Delete one item from the stack, return the deleted item
};

#ifndef STACK_CPP
#include "Stack.cpp" //include implementation as templates are not compiled untill instantiated as a specific type
#endif

#endif