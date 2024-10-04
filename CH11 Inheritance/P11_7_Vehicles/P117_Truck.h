/*	Exercise P11.7. Implement a base class Vehicle and derived classes Car and
Truck. A vehicle has a position on the screen. Write virtual functions draw
that draw cars and trucks as are shown on page 431 of the book. Then populate a
vector of Vehicle* pointers with a mixture of cars and trucks, and draw all of
them.

Bryson Lanterman 20190228
*/

#pragma once
#include "P117_Vehicle.h"

class Truck : public Vehicle
{
public:
	/**
		Constructs a truck as a vehicle with no location
	*/
	Truck();
	/**
		Constructs a truck as a vehicle with the given location
		@param loc Point location of upper left hand corner of the Truck
	*/
	Truck(Point loc);
	/**
		Draws the truck
	*/
	virtual void draw();
};