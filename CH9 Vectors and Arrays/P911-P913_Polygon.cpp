/*	Exercise P9.11. A polygon is a closed sequence of lines. To describe a 
plygon, store the sequence of its corner points. Because the number of points 
is variable, use a vector.

class Polygon
{
public:
	Polygon();
	void add_point(Point p);
	void plot() const;
private:
	vector<Point> corners;
};

Implement this class and supply a test harness that plots a polygon.
*/

/*	Exercise P9.12. Enhance the Polygon class of Exercise P9.11 by adding 
member functions

	double Polygon::perimeter() const

and

	double Polygon::area() const

that compute the perimeter and the area of a polygon. To compute the perimeter, 
compute the distance between adjacent points, and total up the distances.

The area of a polygon with corners (x_0,y_0),...,(x_n-1, y_n-1) is

(1/2) * abs(x_0 * y_1 + x_1 * y_2 + ... + x_n-1 * y_0 
		  - y_0 * x_1 - y_1 * x_2 - ... - y_n-1 * x_0)

As test cases, compute the perimeter and area of a rectangle and of a regular hexagon.

Bryson Lanterman 20180712
*/

/*	Exercise P9.13. Enhance the Polygon class of Exercise P9.11 by adding 
member functions

void Polygon::move(double dx, double dy);
void Polygon::scale(double factor);

the first procedure moves all points of a polygon by the specified amounts in 
the x- and y-directions. The second procedure performs a scaling with the given
scale factor and updates the coordinates of the points of the polygon 
accordingly. Hint: use the move member function of the Point class. To scale a 
point, multipy both the x- and y-coordinate with the scale factor.

Bryson Lanterman 20180717
*/

#include "ccc_win.h"
#include "P911-P913_Polygon.h"
#include <string>

Polygon::Polygon()
{
}

void Polygon::add_point(Point p)
{
	corners.push_back(p);
}

void Polygon::plot() const
{
	if (corners.size() == 0)
	{
		return;
	}

	if (corners.size() == 1)
	{
		cwin << corners[0];
		return;
	}

	cwin << corners[0];

	for (int i = 1; i < corners.size(); i++)
	{
		Line l1(corners[i - 1], corners[i]);
		cwin << corners [i] << l1;
	}

	Line l1(corners[0], corners[corners.size() - 1]);
	cwin << l1;
}

double Polygon::perimeter() const
{
	double polygonPerimeter = 0.0;
	double xSquared = 0.0;
	double ySquared = 0.0;
	double perimeterLessOneSide = 0.0;
	double lastSideLength = 0.0;

	if (corners.size() == 0 || corners.size() == 0)
	{
		return polygonPerimeter;
	}

	for (int i = 1; i < corners.size(); i++)
	{
		xSquared = (corners[i].get_x() - corners[i - 1].get_x()) * (corners[i].get_x() - corners[i - 1].get_x());
		ySquared = (corners[i].get_y() - corners[i - 1].get_y()) * (corners[i].get_y() - corners[i - 1].get_y());
		perimeterLessOneSide += sqrt(xSquared + ySquared);
	}

	xSquared = (corners[0].get_x() - corners[corners.size() - 1].get_x()) * (corners[0].get_x() - corners[corners.size() - 1].get_x());
	ySquared = (corners[0].get_y() - corners[corners.size() - 1].get_y()) * (corners[0].get_y() - corners[corners.size() - 1].get_y());
	lastSideLength = sqrt(xSquared + ySquared);

	polygonPerimeter = perimeterLessOneSide + lastSideLength;

	return polygonPerimeter;
}

double Polygon::area() const
{
	double polygonArea = 0.0;
	if (corners.size() == 0 || corners.size() == 0)
	{
		return polygonArea;
	}
	
	for (int i = 1; i < corners.size(); i++)
	{
		polygonArea += (corners[i - 1].get_x() * corners[i].get_y()) - (corners[i - 1].get_y() * corners[i].get_x());
	}
	polygonArea = abs(polygonArea) / 2.0;
	return polygonArea;
}

void Polygon::move(double dx, double dy) 
{
	for(int i = 0; i < corners.size(); i++)
	{
		corners[i].move(dx, dy);
	}
}

void Polygon::scale(double factor)
{
	for(int i = 0; i < corners.size(); i++)
	{
		corners[i] = Point(corners[i].get_x() * factor, corners[i].get_y() * factor);
	}
}