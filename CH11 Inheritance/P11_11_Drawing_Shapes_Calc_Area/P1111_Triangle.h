/*	Exercise P11.11. Implement a base class Shape and derived classes 
Rectangle, Triangle, and Square. Derive Square from Rectangle. Supply virtual
functions double area() and void plot(). Fill a vector of Shape* pointers with
a mixture of the sapes, plot them all, and compute the total area.

Bryson Lanterman 20190429
*/

#pragma once

#include "ccc_win.h"
#include "P1111_Shape.h"

class Triangle : public Shape
{
public:
	/**
		Constructs an (equilateral) Triangle object with no location
	*/
	Triangle();
	/**
		Constructs an (equilateral) Triangle object with base length and location
		@param loc Point location of lower left hand corner
		@param b base length
	*/
	Triangle(Point loc, double b);
	/**
		Returns Area of the Triangle object
		@return area of Triangle
	*/
	virtual double get_area() const;
	/**
		Plots the Triangle on the xy plane
	*/
	virtual void plot();
private:
	double base;
};