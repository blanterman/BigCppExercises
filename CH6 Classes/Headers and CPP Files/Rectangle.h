#include "ccc_win.h"

class Rectangle
{
public:
	/**
		Default Constructor of a Rectangle object
	*/
	Rectangle();

	/**
		Constructor for a rectangle object given two corner points
	*/
	Rectangle(Point c1, Point c2);

	/**
		Moves the rectangle.
		@param dx double distance to move the rectangle in the x-direction
		@param dy double distance to move the rectangle in the y-direction
	*/
	void move(double dx, double dy);

	/**
		Returns the perimeter of the rectangle
	*/
	double get_perimeter() const;

	/**
		Returns the Area of the rectangle
	*/
	double get_area() const;

	/**
		Draws the rectangle in the cwin window
	*/
	void plot() const;

private:
	Point corner1;
	Point corner2;
};