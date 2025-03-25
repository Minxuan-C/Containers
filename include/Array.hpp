/*
header file for array class
*/
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <sstream>
#include <cmath>
#include <iostream>
#include <string>
#include "Exception.hpp"

template <typename T> //template with generic type T
class Array {
private:
	static int defaultsize; //static member data
	T* m_data; //member data, pointer to an array of type T
	int m_size; //member data, size of array
public:
	Array(); //default constructor
	Array(const int size); //parameterized constructor
	Array(const Array<T>& source); //copy constructor of type Array<T>
	~Array(); //destructor
	Array<T>& operator =(const Array<T>& source); //assignment operator which returns a reference of Array<T>
	int Size() const; //getter for size
	void SetElement(int idx, const T &t); //setter for elements of m_data through index specification, takes in a type T reference
	const T& GetElement(int inx) const; //getter for elements of m_data through index specification
	T& operator [] (int idx); //getter and setter combined through index specification and operator overloading
	const T& operator [] (int idx) const; //const version
	int static DefaultSize(); //getter for default size 
	void static DefaultSize(const int new_num); //setter for default size
};

#ifndef ARRAY_CPP
#include "Array.cpp" //include implementation as templates are not compiled untill instantiated as a specific type
#endif

#endif