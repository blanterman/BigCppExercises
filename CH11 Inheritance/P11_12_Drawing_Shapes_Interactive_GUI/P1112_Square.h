/*	Exercise P11.11. Implement a base class Shape and derived classes 
Rectangle, Triangle, and Square. Derive Square from Rectangle. Supply virtual
functions double area() and void plot(). Fill a vector of Shape* pointers with
a mixture of the sapes, plot them all, and compute the total area.

Bryson Lanterman 20190429

Exercise P11.12. Use the preceding exercise as the basis for a drawing program.
Users can place various shapes onto the screen by first clicking on a shape 
icon and then clicking on the desired screen location.

Bryson Lanterman 20190501
*/

#pragma once

#include "ccc_win.h"
#include "P1112_Rectangle.h"

class Square : public Rectangle
{
public:
	/**
		Constructs a square object with no location
	*/
	Square();
	/**
		Constructs a square object with height, width and location
		@param loc Point location of lower left hand corner
		@param w width and height of square
	*/
	Square(Point loc, double w);
	/**
		Returns Area square object (w * w)
		@return area of square
	*/
	virtual double get_area();
	/**
		Plots the square on the xy plane
	*/
	virtual void plot();
};