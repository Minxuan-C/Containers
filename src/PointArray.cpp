/*
implement PointArray class
*/
#include "PointArray.hpp"

PointArray::PointArray() :Array<Point>() {} //calls base default constructor of Point type

PointArray::PointArray(int size) : Array<Point>(size) {} //calls base parameterized constructor

PointArray::PointArray(const PointArray& source) : Array<Point>(source) {} //calls base copy constructor

PointArray::~PointArray() {} //base destructor will be automatically called, so empty here

PointArray& PointArray:: operator =(const PointArray& source) { //assignment operator
	if (this == &source) return *this; //check to avoid self-assignment
	Array<Point>::operator = (source); //calls base assignment operator of Point type since no new data member created
	return *this; //return reference
}

double PointArray::Length() {
	if (this->Size() < 2) return 0;
	double sum = 0; //initialize a double to keep track of addition results
	for (int i = 1; i < this->Size(); i++) { //start with i=1
		const Point& prev = (*this)[i - 1];  //previous point reference
		const Point& curr = (*this)[i];  //current point reference
		sum += prev.Distance(curr);  //use Distance() between points
	}
	return sum; //return a result
}
