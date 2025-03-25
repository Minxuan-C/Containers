/*
declare PointArray class
*/
#ifndef POINTARRAY_HPP
#define POINTARRAY_HPP
#include "Point.hpp"
#include "Array.hpp"

class PointArray :public Array<Point> { //inherit from Array of type Point
public:
	PointArray(); //default constructor
	PointArray(int size); //parameterized constructor
	PointArray(const PointArray& source); //copy constructor
	~PointArray(); //destructor
	PointArray& operator =(const PointArray& source); //assignment operator
	double Length(); //length function that returns total distance of points
};

#endif