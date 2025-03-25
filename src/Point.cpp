/* 
implementation of point class
*/
#include <sstream>
#include <cmath>
#include "Point.hpp"

Point::Point(): Shape(),m_x(0),m_y(0){} //call default constructor of base class

Point::Point(double num) :Shape(),m_x(num),m_y(num) {} //call default constructor of base class

Point::Point(double x, double y) : Shape(), m_x(x), m_y(y) {} //call default constructor of base class

Point::Point(const Point &p):Shape(p),m_x(p.m_x),m_y(p.m_y) {} //call copy constructor of base class

Point::~Point() {}

double Point::X() const {return m_x;}

double Point::Y() const {return m_y;}

void Point::X(double x_new) {m_x = x_new;}

void Point::Y(double y_new) {m_y = y_new;}

std::string Point::ToString() const {
	std::stringstream ss;
	ss << "Point(" << m_x << "," << m_y << ")"; 
	std::string s = Shape::ToString();
	return ss.str() + "\n" + s; //add shape description after point description and return
}

double Point::Distance() const {
	return std::sqrt(std::pow(m_x,2) + std::pow(m_y, 2));
}

double Point::Distance(const Point &p) const {
	return std::sqrt(std::pow(m_x - p.m_x, 2) + std::pow(m_y - p.m_y, 2));
}

/*Demonstration of operator overloading*/
Point Point:: operator - () const { //Negate the coordinates, return a new object
	return Point(-m_x, -m_y);
}

Point Point:: operator * (double factor) const { // Scale the coordinates, return a new object
	return Point(m_x * factor, m_y * factor);
}

Point Point:: operator + (const Point& p) const { // Add coordinates, return a new object
	return Point(m_x + p.m_x, m_y + p.m_y);
}

bool Point:: operator == (const Point& p) const { // Equally compare operator, return True or False
	return m_x == p.m_x && m_y == p.m_y;
}

Point& Point::operator = (const Point& source) {// Assignment operator, return reference; add check to avoid self-assignment
	if (this == &source) {
		return *this;
	}
	else {
		Shape::operator=(source); //call base class = operator
		m_x = source.m_x;
		m_y = source.m_y;
		return *this;
	}
} 

Point& Point::operator *= (double factor) { // Scale the coordinates & assign, return reference
	Point temp = *this * factor;
	*this = temp;
	return *this;
}

std::ostream& operator << (std::ostream& os, const Point& p) {// Send to ostream, global function; print by accessing member data of p direcrly
	os << "x is: " << p.m_x << "," << "y is: " << p.m_y;
	return os;
}
