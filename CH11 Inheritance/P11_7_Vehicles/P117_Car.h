/*	Exercise P11.7. Implement a base class Vehicle and derived classes Car and
Truck. A vehicle has a position on the screen. Write virtual functions draw
that draw cars and trucks as are shown on page 431 of the book. Then populate a
vector of Vehicle* pointers with a mixture of cars and trucks, and draw all of
them.

Bryson Lanterman 20190228
*/

#pragma once
#include "P117_Vehicle.h"

class Car : public Vehicle
{
public:
	/**
		Constructs a car as a vehicle without a location
	*/
	Car();
	/**
		Constructs a car as a vehicle with given location
		@param loc location of the upper left hand corner of the car
	*/
	Car(Point loc);
	/**
		Draws a car
	*/
	virtual void draw();
};