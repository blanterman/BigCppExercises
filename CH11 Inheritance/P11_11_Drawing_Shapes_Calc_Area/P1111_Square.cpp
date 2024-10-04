/*	Exercise P11.11. Implement a base class Shape and derived classes 
Rectangle, Triangle, and Square. Derive Square from Rectangle. Supply virtual
functions double area() and void plot(). Fill a vector of Shape* pointers with
a mixture of the sapes, plot them all, and compute the total area.

Bryson Lanterman 20190429
*/

#include "ccc_win.h"
#include "P1111_Square.h"

Square::Square()
	:Rectangle()
{

}

Square::Square(Point loc, double w)
	:Rectangle(loc, w, w)
{

}

double Square::get_area()
{
	return Rectangle::get_width() * Rectangle::get_width();
}

void Square::plot()
{
	Point p1 = Shape::get_location();
	Point p2 = p1;
	p2.move(0.0, Rectangle::get_width());
	Line l1(p1, p2);
	Line l3 = l1;
	l3.move(Rectangle::get_width(), 0.0);

	p2.move(Rectangle::get_width(), -Rectangle::get_width());
	Line l2(p1, p2);
	Line l4 = l2;
	l4.move(0.0, Rectangle::get_width());

	cwin << l1 << l2 << l3 << l4;
}