/* 
header file for point class
*/
#ifndef POINT_HPP
#define POINT_HPP
#include "Shape.hpp"

class Point: public Shape {
private:
	double m_x, m_y;
public:
	Point();
	explicit Point(double num);
	Point(double x, double y);
	Point(const Point &p);
	~Point();
	double X() const;
	double Y() const;
	void X(double x_new);
	void Y(double y_new);
	std::string ToString() const;
	double Distance() const;
	double Distance(const Point &p) const;

	Point operator - () const; // Negate the coordinates.
	Point operator * (double factor) const; // Scale the coordinates.
	Point operator + (const Point& p) const; // Add coordinates.
	bool operator == (const Point& p) const; // Equally compare operator.
	Point& operator = (const Point& source); // Assignment operator.
	Point& operator *= (double factor); // Scale the coordinates & assign.

	friend std::ostream& operator << (std::ostream& os, const Point& p); // Send to ostream, global function; declare inside Point class as friend

};



#endif