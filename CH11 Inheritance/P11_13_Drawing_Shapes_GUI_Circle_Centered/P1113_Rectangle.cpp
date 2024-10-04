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
#include "P1113_Rectangle.h"

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
	p1.move(-0.5 * width, 0.5 * height);
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