/*	Exercise P11.11. Implement a base class Shape and derived classes 
Rectangle, Triangle, and Square. Derive Square from Rectangle. Supply virtual
functions double area() and void plot(). Fill a vector of Shape* pointers with
a mixture of the sapes, plot them all, and compute the total area.

Bryson Lanterman 20190429
*/

#pragma once

#include "ccc_win.h"

class Shape
{
public:
	/**
		Constructs a shape object with no location
	*/
	Shape();
	/**
		Constructs a shape object with location
		@param loc Point location of the shape object's lower left hand corner
	*/
	Shape(Point loc);
	/**
		Returns the location of the shape object
		@return location of the lower left hand corner of the shape object
	*/
	Point get_location() const;
	/**
		Computes and returns the area of the shape object
	*/
	virtual double get_area();
	/**
		Plots the shape
	*/
	virtual void plot();
private:
	Point location;
};