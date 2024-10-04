/*	Exercise P11.11. Implement a base class Shape and derived classes 
Rectangle, Triangle, and Square. Derive Square from Rectangle. Supply virtual
functions double area() and void plot(). Fill a vector of Shape* pointers with
a mixture of the sapes, plot them all, and compute the total area.

Bryson Lanterman 20190429

Exercise P11.12. Use the preceding exercise as the basis for a drawing program.
Users can place various shapes onto the screen by first clicking on a shape 
icon and then clicking on the desired screen location.

Bryson Lanterman 20190501

Exercise P11.13. Extend the program of the preceding exercise by adding another
shape type: CircleShape. (You cannot call it Circle, because there already is a
Circle class in the graphics library.) Explain what changes you needed to make 
in the program to implement this extension. How do virtual functions help in 
making the program easily extensible?

Bryson Lanterman 20190501
*/

#pragma once

#include "ccc_win.h"
#include "P1113_Shape.h"

class Rectangle : public Shape
{
public:
	/**
		Constructs a rectangle object with no location
	*/
	Rectangle();
	/**
		Constructs a rectangle object with height, width and location
		@param loc Point location of lower left hand corner
		@param h height of rectangle (y-direction)
		@param w width of rectangel (x-direction)
	*/
	Rectangle(Point loc, double h, double w);
	/**
		Returns Area rectangle object (h * w)
		@return area of rectangle
	*/
	virtual double get_area() const;
	/**
		Returns width of rectangle object
		@return width of rectangle
	*/
	virtual double get_width() const;
	/**
		Plots the rectangle on the xy plane
	*/
	virtual void plot();
private:
	double height;
	double width;
};