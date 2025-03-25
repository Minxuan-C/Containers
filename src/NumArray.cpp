/*
implement NumericArray
*/

#ifndef NUMARRAY_CPP
#define NUMARRAY_CPP 

#include "NumArray.hpp"

template <typename T>
NumericArray<T>::NumericArray() :Array<T>() {} //calls base default constructor

template <typename T>
NumericArray<T>::NumericArray(int size) : Array<T>(size) {} //calls base parameterized constructor

template<typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& source):Array<T>(source){} //calls base copy constructor

template <typename T>
NumericArray<T>::~NumericArray(){} //base destructor will be automatically called, so empty here

template <typename T>
NumericArray<T>& NumericArray<T>:: operator =(const NumericArray<T>& source) { //assignment operator
	if (this == &source) return *this; //check to avoid self-assignment
	Array<T>::operator = (source); //calls base assignment operator since no new data member created
	return *this; //return reference
}
template <typename T>
NumericArray<T> NumericArray<T>:: operator *(double factor) const { //scaling operator, return an object
	NumericArray<T> newarr(this->Size()); //initialize a numeric array object of the same size
	for (int i = 0; i < this->Size(); i++) { //loop over element
		newarr[i] = (*this)[i] * factor; //each element is scaled by the factor
	}//the implicit condition is that class T should have * operator that supports multiplication with a double
	return newarr; //return the numarray object
}

template <typename T>
NumericArray<T> NumericArray<T>:: operator +(const NumericArray<T>& source) const { //+ operator
	if (this->Size() != source.Size()) throw ArrayException(); //check for size, if not equal throw a generic exception
	NumericArray<T> newarr(this->Size());//initialize a numeric array object of the same size
	for (int i = 0; i < this->Size(); i++) {
		newarr[i] = (*this)[i] + source[i]; //the implicit condition is that class T should support object-wise addition
	}
	return newarr;
}

template <typename T>
double NumericArray<T>::DotProduct(const NumericArray<T>& source) const { //dot product
	if (this->Size() != source.Size()) throw ArrayException(); //check for size, if not equal throw a generic exception
	double sum = 0; //initialize a double to keep track of addition results
	for (int i = 0; i < this->Size(); i++) {
		sum += ((*this)[i] * source[i]); //the implicit condition here is that class T should support element-wise multiplication, and that the result is compatible with double type.
	}//for example, int/float should be fine, as they can be implicitly converted to double
	return sum; //return a result
}

#endif