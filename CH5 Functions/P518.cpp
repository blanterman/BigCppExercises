#include "ccc_win.h"

using namespace std;

const double PI = 3.14159265358979323;
const double D2R = PI / 180.0;
/**
	Takes a point and rotates it about the origin in a CCW direction by a given angle
	@param p Point object to be rotated
	@param angle double value of the angle the point is to be rotated about the origin
*/
void rotate(Point& p, double angle)
{
	p = Point(p.get_x() * cos(angle) - p.get_y() * sin(angle), p.get_x() * sin(angle) + p.get_y() * cos(angle));
}

/**
	Take a point vector and scales its length.
	@param p Point object to be scaled
	@param scale double scale factor
*/
void scale(Point& p, double scale)
{
	p = Point(scale * p.get_x(), scale * p.get_y());
}

int ccc_win_main()
{
	Point xl(-10.0, 0.0);
	Point xr = xl;
	xr.move(20.0, 0.0);
	Line xaxis(xl, xr);

	Point yd(0.0, -10.0);
	Point yu = yd;
	yu.move(0.0, 20.0);
	Line yaxis(yd, yu);

	cwin << xaxis << yaxis;
	Point O(0.0, 0.0);
	Point p1 = cwin.get_mouse("select a point");
	Line l1(O, p1);
	cwin << p1 << l1; // user feedback
	double angle = cwin.get_double("what angle would you like to rotate it by?");
	angle = D2R * angle;
	double scalef = cwin.get_double("scale by what factor?");

	rotate(p1, angle);
	scale(p1, scalef);

	Line l2(O, p1);
	cwin << p1 << l2; // user feedback
	return 0;
}