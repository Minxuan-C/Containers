/*
declare Shape class
*/
#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>

class Shape {
private:
	int m_id; //private data member
public:
	Shape(); //default constructor
	Shape(const Shape &source); //copy constructor
	virtual ~Shape(); //destructor
	Shape& operator = (const Shape &source); //assignment operator
	virtual std::string ToString() const; //function to print out text,declared as virtual
	int ID() const; //getter for m_id
};



#endif