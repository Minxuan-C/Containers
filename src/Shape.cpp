/*
define Shape class
*/
#include <sstream>
#include <stdlib.h>
#include "Shape.hpp"

Shape::Shape() :m_id(rand()) {}; //default constructor with a random ID

Shape::Shape(const Shape& source) :m_id(source.m_id) {}; //copy constructor

Shape::~Shape() {}; //destructor

Shape& Shape:: operator = (const Shape& source) { //copy constructor
	m_id = source.m_id;
	return *this;
}

std::string Shape::ToString() const{ //function to print out m_id
	std::stringstream ss;
	ss << "ID: " << m_id;
	return ss.str();
}

int Shape::ID() const {return m_id;} //getter for m_id
