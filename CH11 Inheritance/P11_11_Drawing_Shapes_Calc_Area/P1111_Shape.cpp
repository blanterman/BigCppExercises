/*	Exercise P11.11. Implement a base class Shape and derived classes 
Rectangle, Triangle, and Square. Derive Square from Rectangle. Supply virtual
functions double area() and void plot(). Fill a vector of Shape* pointers with
a mixture of the sapes, plot them all, and compute the total area.

Bryson Lanterman 20190429
*/

#include "ccc_win.h"
#include "P1111_Shape.h"

Shape::Shape()
{

}

Shape::Shape(Point loc)
{
	location = loc;
}

Point Shape::get_location() const
{
	return location;
}

double Shape::get_area()
{
	return 0.0;
}

void Shape::plot()
{

}