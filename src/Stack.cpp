/*
declare class Stack
*/
#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"


template <typename T, int size>
Stack<T,size>::Stack() : m_array(Array<T>(size)),m_current(0){} // default constructor, initialize m_array using parameterized constructor of Array of type T of size "size" and the current position of 0 - array object is created inside stack so composition

template<typename T, int size>
Stack<T,size>::Stack(const Stack<T,size>& source) : m_array(source.m_array), m_current(source.m_current){} //copy constructor; note that index is also copied

template <typename T, int size>
Stack<T, size>::~Stack() {} //default destructor

template <typename T, int size>
Stack<T, size>& Stack<T, size>:: operator =(const Stack<T, size>& source) { //assignment operator
	if (this == &source) return *this; //check to avoid self-assignment
	m_array = source.m_array; 
	m_current = source.m_current;
	return *this; //return reference
}

template <typename T, int size>
void Stack<T, size>::Push(const T& item) { //push function
	if (m_current >= size) { //check for stack overflow
		throw StackFullException(); //throw stack full exception
	}
	m_array[m_current] = item; //set value
	m_current++; //increment of index
}

template <typename T, int size>
T Stack<T, size>::Pop() { //pop function - return object of type T to accomadate exception-throwing mechanism
	if (m_current == 0) { //check for stack underflow
		throw StackEmptyException();//throw stack empty exception - no need to reset m_current because the m_current-- part will not be executed if Exception occurs 
	}
	m_current--;
	return m_array[m_current];
}
#endif