#include "ccc_win.h"
#include "Rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(Point c1, Point c2)
{
	corner1 = c1;
	corner2 = c2;
}

void Rectangle::move(double dx, double dy)
{
	corner1.move(dx, dy);
	corner2.move(dx, dy);
}


double Rectangle::get_perimeter() const
{
	return 2 * abs(corner1.get_x() - corner2.get_x()) + 2 * abs(corner1.get_y() - corner2.get_y());
}

double Rectangle::get_area() const
{
	return abs(corner1.get_x() - corner2.get_x()) * abs(corner1.get_y() - corner2.get_y());
}

void Rectangle::plot() const
{
	Point p1 = corner1;
	p1.move(corner2.get_x() - corner1.get_x(), 0.0);
	Line l1(corner1, p1);
	Line l2 = l1;
	l2.move(0.0, corner2.get_y() - corner1.get_y());
	Line l3(p1, corner2);
	Line l4 = l3;
	l4.move(corner1.get_x() - corner2.get_x(), 0.0);
	cwin << l1 << l2 << l3 << l4;
}
