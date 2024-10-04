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

As test cases, compute the perimeter and area of a rectangle and of a regular 
hexagon.

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
#include <vector>

class Polygon
{
public:
	/**
		P911
		Default Constructor of a Polygon object
	*/
	Polygon();

	/**
		P911
		Adds a point to the Polygon object representing a corner of a polygon
		@param p Point object to add
	*/
	void add_point(Point p);

	/**
		P911
		Draws the polygon in the cwin window
	*/
	void plot() const;

	/**
		P912
		Computes the perimeter of a polygon object
	*/
	double perimeter() const;

	/**
		P912
		Computes the area of a polygon object
	*/
	double area() const;

	/**
		P913
		Moves all points of a polygon by the specified amounts in the x- and 
		y-directions.
		@param dx amount to move the points in the x-direction
		@param dy amount to move the points in the y-direction
	*/
	void move(double dx, double dy);

	/**
		P913
		Performs a scaling with the given scale factor and updates the 
		coordinates of the poinsts of the polygon accordingly.
		@param factor the factor by which to scale the points of the polygon.
	*/
	void scale(double factor);

private:
	vector<Point> corners;
};