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


#include "P911-P913_Polygon.h"

int ccc_win_main()
{
	//P913
	cwin.coord(-1.0, 15.0, 9.0, -1.0);
	Polygon poly1;
	poly1.add_point(Point(1.0, 0.0));
	poly1.add_point(Point(0.0, 3.0));
	poly1.add_point(Point(0.0, 9.0));
	poly1.add_point(Point(3.0, 14.0));
	poly1.add_point(Point(7.0, 11.0));
	poly1.add_point(Point(8.0, 6.0));
	poly1.add_point(Point(6.0, 0.0));
	poly1.plot();

	poly1.move(1.0, 1.0);
	poly1.plot();

	poly1.scale(0.5);
	poly1.plot();

	return 0;
}