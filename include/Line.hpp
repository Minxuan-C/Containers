/* 
header file for line class
*/
#ifndef LINE_HPP
#define LINE_HPP
#include "Point.hpp"

class Line:public Shape { //add inheritance
private:
	Point p1, p2;
public:
	Line();
	Line(const double num);
	Line(const Point& pnt1, const Point& pnt2);
	Line(const Line& l);
	~Line();
	const Point& P1();
	const Point& P2();
	void P1(const Point& pnt1);
	void P2(const Point& pnt2);
	std::string ToString() const;
	double Length() const;
	Line& operator = (const Line& source); // Assignment operator.
	friend std::ostream& operator << (std::ostream& os, const Line& l); // Send to ostream, global function; declare inside Line class as friend
	void Draw(); //declaration
};

#endif