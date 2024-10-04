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
#include "ccc_win.h"
#include "P1113_Shape.h"

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