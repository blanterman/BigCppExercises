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
#include "P1112_Triangle.h"

Triangle::Triangle()
	:Shape()
{

}

Triangle::Triangle(Point loc, double b)
	:Shape(loc)
{
	base = b;
}


double Triangle::get_area() const
{
	return base * base * sqrt(3.0) / 4.0;
}

void Triangle::plot()
{
	Point p1 = Shape::get_location();
	Point p2 = p1;
	p2.move(base, 0.0);
	Point p3 = p1;
	p3.move(0.5 * base, -sqrt(3.0) * base / 2.0);
	Line l1(p1, p2);
	Line l2(p1, p3);
	Line l3(p2, p3);

	cwin << l1 << l2 << l3;
}