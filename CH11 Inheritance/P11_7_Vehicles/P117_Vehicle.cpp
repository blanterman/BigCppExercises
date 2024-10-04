/*	Exercise P11.7. Implement a base class Vehicle and derived classes Car and
Truck. A vehicle has a position on the screen. Write virtual functions draw
that draw cars and trucks as are shown on page 431 of the book. Then populate a
vector of Vehicle* pointers with a mixture of cars and trucks, and draw all of
them.

Bryson Lanterman 20190228
*/

#include "P117_Vehicle.h"

Vehicle::Vehicle()
{

}

Vehicle::Vehicle(Point loc)
{
	location = loc;
}

Point Vehicle::get_loc() const
{
	return location;
}

void Vehicle::draw()
{
	
}