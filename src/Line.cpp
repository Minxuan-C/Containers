/* 
implementation of line class

add new constructor for template array testing
*/
#include <sstream>
#include <iostream>
#include "Line.hpp"

Line::Line() :Shape(),p1(0, 0), p2(0, 0) {} //call default constructor of base class

Line::Line(double num) :Shape(), p1(Point(num)), p2(Point(num)) {} //takes in one argument to initialize

Line::Line(const Point& pnt1, const Point& pnt2) : Shape(),p1(pnt1), p2(pnt2) {} //call default constructor of base class

Line::Line(const Line& l) :Shape(l),p1(l.p1), p2(l.p2) {} //call copy constructor of base class

Line::~Line() {}

const Point& Line::P1() { return p1; }

const Point& Line::P2() { return p2; }

void Line::P1(const Point& pnt1){
	p1 = pnt1;
}

void Line::P2(const Point& pnt2){
	p2 = pnt2;
}

std::string Line::ToString() const {
	std::stringstream ss;
	ss << "Point1(" << p1.X() << "," << p1.Y() << ")\t";
	ss << "Point2(" << p2.X() << "," << p2.Y() << ")";
	std::string s = Shape::ToString();
	return ss.str() + "\n" + s; //add shape description after line description and return
}

double Line::Length() const {
	return p1.Distance(p2);
}

Line& Line:: operator = (const Line& source){// Assignment operator, return reference; add check to avoid self-assignment
	if (this == &source) {
		return *this;
	}
	else {
		Shape::operator=(source); //call base class = operator
		p1 = source.p1;
		p2 = source.p2;
		return *this;
	}
}

std::ostream& operator << (std::ostream& os, const Line& l) {// Send to ostream, global function; print by calling tostring method of Line class
	os << "p1( " << l.p1 << ")\n";
	os << "p2( " << l.p2 << ")\n";
	return os;
}
