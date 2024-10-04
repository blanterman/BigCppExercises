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

#include "ccc_win.h"
#include "P1112_Rectangle.h"

Rectangle::Rectangle()
	:Shape()
{

}

Rectangle::Rectangle(Point loc, double h, double w)
	:Shape(loc)
{
	height = h;
	width = w;
}

double Rectangle::get_area() const
{
	return height * width;
}

double Rectangle::get_width() const
{
	return width;
}

void Rectangle::plot()
{
	Point p1 = Shape::get_location();
	Point p2 = p1;
	p2.move(0.0, -height);
	Line l1(p1, p2);
	Line l3 = l1;
	l3.move(width, 0.0);

	p2.move(width, height);
	Line l2(p1, p2);
	Line l4 = l2;
	l4.move(0.0, -height);

	cwin << l1 << l2 << l3 << l4;
}