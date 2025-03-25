/*
implementation of array class
*/
#ifndef Array_CPP
#define Array_CPP 

#include "Array.hpp"

template <typename T> //template 
int Array<T>::defaultsize = 10; //initialize default size to be 10

template <typename T>
Array<T>::Array(): m_data(new T[defaultsize]), m_size(defaultsize){} //default constructor, allocate memory and initialize array on heap with default constructor of T, of default size

template <typename T>
Array<T>::Array(const int size) : m_data(new T[size]), m_size(size){} //parameterized constructor, takes in size argument and allocate memory/initialize on heap accordingly

template <typename T>
Array<T>::Array(const Array<T> &source) { //copy constructor
	m_size = source.m_size; //copy the size from source
	m_data = new T[m_size]; //allocate memory based on the source size
	for (int i = 0;i < source.m_size;i++) { //deep copy of elements through loop and indexing
		m_data[i] = source.m_data[i]; 
	}
}

template <typename T>
Array<T>::~Array() { //destructor of array, no need to care about m_size as this is on stack
	delete[] m_data;
	std::cout << "array<" << typeid(T).name() << "> destructor called\n"; //print if destructor called
} 

template <typename T>
Array<T>& Array<T>::operator =(const Array<T>& source) { //assignment operator, return a reference of Array<T>
	if (this == &source) return *this; //check if the source and the current object are stored in the same memory, to avoid self-assignment

	delete[] m_data; //free old memory of the current object
	m_size = source.m_size; //set new size the same as the source
	m_data = new T[m_size]; //allocate memory based on new size

	for (int i = 0;i < m_size;i++) { //loop over to create deep copy
		m_data[i] = source.m_data[i];
	}
	return *this; //return address
}

template <typename T>
int Array<T>::Size() const { return m_size; } //getter for m_size

template <typename T>
void Array<T>::SetElement(int idx, const T& t) { //setter for elements of m_data through index specification
	if (idx >= m_size || idx < 0) throw OutOfBoundsException(idx); //throw exception of derived error class when index not valid; initialize with index number
	m_data[idx] = t;
}

template <typename T>
const T& Array<T>::GetElement(int idx) const { //getter for elements of m_data through index specification; return T object reference
	if (idx >= m_size || idx < 0) throw OutOfBoundsException(idx); //also add const return type keyword to make sure read-only access beyond function execution
	return m_data[idx]; //throw exception of derived error class when index not valid; initialize with index number
}

template <typename T>
T& Array<T>::operator [] (int idx) {
	if (idx >= m_size || idx < 0) throw OutOfBoundsException(idx); //getter and setter for elements of m_data through index specification and operator overloading; return T object reference
	return m_data[idx]; //note that there is no const keyword for return type, effectively allowing for both reading and modification
}//throw exception of derived error class when index not valid; initialize with index number

template <typename T>
const T& Array<T>::operator [] (int idx) const{
	if (idx >= m_size || idx < 0) throw OutOfBoundsException(idx); //add a const version with same functionality to allow for different (modification) behavior based on the initialization of instance, i.e., const array vs array
	return m_data[idx];//throw exception of derived error class when index not valid; initialize with index number
}

template <typename T>
int Array<T>::DefaultSize() { return defaultsize; } //getter for default size

template <typename T>
void Array<T>::DefaultSize(int new_num) { //setter for default size
	defaultsize = new_num; 
}

#endif