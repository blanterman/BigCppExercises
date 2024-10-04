#include "ccc_win.h"

class Triangle
{
public:
	/**
		Constructor default
	*/
	Triangle();

	/**
		Constructor of the triangle given all three points 
	*/
	Triangle(Point c1, Point c2, Point c3);

	/**
		Moves the triangle
		@param dx double distance to move the rectangle in the x-direction
		@param dy double distance to move the rectangel in the y-direction
	*/
	void move(double dx, double dy);

	/**
		Returns the Perimeter of the triangle
	*/
	double get_perimeter() const;

	/**
		Returns the Area of the triangle
	*/
	double get_area() const;

	/**
		Draws the triangle in the cwin window
	*/
	void plot() const;

private:
	Point corner1;
	Point corner2;
	Point corner3;
};