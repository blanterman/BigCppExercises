#include "ccc_win.h"
#include "Triangle.h"

Triangle::Triangle()
{
}

Triangle::Triangle(Point c1, Point c2, Point c3)
{
	corner1 = c1;
	corner2 = c2;
	corner3 = c3;
}

void Triangle::move(double dx, double dy)
{
	corner1.move(dx, dy);
	corner2.move(dx, dy);
	corner3.move(dx, dy);
}

double Triangle::get_perimeter() const
{
	double side1 = 0.0, side2 = 0.0, side3 = 0.0;
	side1 = sqrt((corner1.get_x() - corner2.get_x()) * (corner1.get_x() - corner2.get_x()) + (corner1.get_y() - corner2.get_y()) * (corner1.get_y() - corner2.get_y()));
	side2 = sqrt((corner2.get_x() - corner3.get_x()) * (corner2.get_x() - corner3.get_x()) + (corner2.get_y() - corner3.get_y()) * (corner2.get_y() - corner3.get_y()));
	side3 = sqrt((corner1.get_x() - corner3.get_x()) * (corner1.get_x() - corner3.get_x()) + (corner1.get_y() - corner3.get_y()) * (corner1.get_y() - corner3.get_y()));
	return side1 + side2 + side3;
}

double Triangle::get_area() const
{
	double ax = corner1.get_x();
	double ay = corner1.get_y();
	double bx = corner2.get_x();
	double by = corner2.get_y();
	double cx = corner3.get_x();
	double cy = corner3.get_y();

	// This equation of the area of a triangle given the coordinates
	// of the vertices was found at:
	// http://www.mathopenref.com/coordtrianglearea.html
	return abs((ax * (by - cy) + bx * (cy - ay) + cx * (ay - by))/2.0);
}

void Triangle::plot() const
{
	Line l1(corner1, corner2);
	Line l2(corner2, corner3);
	Line l3(corner3, corner1);
	cwin << l1 << l2 << l3;
}