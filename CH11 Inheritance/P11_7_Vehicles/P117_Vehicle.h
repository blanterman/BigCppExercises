/*	Exercise P11.7. Implement a base class Vehicle and derived classes Car and
Truck. A vehicle has a position on the screen. Write virtual functions draw
that draw cars and trucks as are shown on page 431 of the book. Then populate a
vector of Vehicle* pointers with a mixture of cars and trucks, and draw all of
them.

Bryson Lanterman 20190228
*/

#pragma once
#include "ccc_win.h"

class Vehicle
{
public:
	/**
		Constructs a vehicle with no position
	*/
	Vehicle();
	/**
		Constructs a vehicle with given x,y point position as its upper left hand corner
		@param loc point location of the upper left hand position of the vehicle
	*/
	Vehicle(Point loc);
	/**
		Gets the vehicles location
		@return location point of the vehicle
	*/
	Point get_loc() const;
	/**
		Draws the vehicle
	*/
	virtual void draw();
private:
	Point location;
};