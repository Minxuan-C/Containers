/*
declare derived class NumericArray
*/
#ifndef NUMARRAY_HPP
#define NUMARRAY_HPP
#include "Array.hpp"
#include "Exception.hpp"


template <typename T> //template with generic type T
class NumericArray:public Array<T> { //generic public inheritance
public:
	NumericArray(); //default constructor
	NumericArray(int size); //parameterized constructor
	NumericArray(const NumericArray<T>& source); //copy constructor
	~NumericArray(); //destructor
	NumericArray<T>& operator =(const NumericArray<T>& source); //assignment operator
	NumericArray<T> operator *(double factor) const; //scaling operator
	NumericArray<T> operator +(const NumericArray<T>& source) const; //object addition operator
	double DotProduct(const NumericArray<T>& source) const; //dot product function
};
#ifndef NUMARRAY_CPP
#include "NumArray.cpp" //include implementation as templates are not compiled untill instantiated as a specific type
#endif

#endif