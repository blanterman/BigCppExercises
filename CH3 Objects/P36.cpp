#include "ccc_win.h"

int ccc_win_main()
{
	// Get the three points from the user
	Point p1 = cwin.get_mouse("Select 3 points");
	cwin << p1; // User feedback
	Point p2 = cwin.get_mouse("Select 3 points");
	cwin << p2; // User feedback
	Point p3 = cwin.get_mouse("Select 3 points");
	
	// Compute slope of line perpendicular to the line made by p1 and p2
	double slope1 = -(p2.get_x() - p1.get_x()) / (p2.get_y() - p1.get_y());
	
	// Compute the midpoint of the line made by p1 and p2
	Point mp1 = p1;
	mp1.move((p2.get_x() - p1.get_x()) / 2.0, (p2.get_y() - p1.get_y()) / 2.0);
	
	// Compute the y intercept of the perpendicular bisector of the line made by p1 and p2
	double b1 = mp1.get_y() - slope1 * mp1.get_x(); // Now we have equation of perp bisector

	// Compute slope of line perpendicular to the line made by p2 and p3
	double slope2 = -(p3.get_x() - p2.get_x()) / (p3.get_y() - p2.get_y());
	
	// Compute the midpoint of the line made by p2 and p3
	Point mp2 = p2;
	mp2.move((p3.get_x() - p2.get_x()) / 2.0, (p3.get_y() - p2.get_y()) / 2.0);
	
	// Compute the y intercept of the perpendicular bisector of the line made by p2 and p3
	double b2 = mp2.get_y() - slope2 * mp2.get_x(); // Now we have equation of perp bisector

	// Compute the x and y values of the intersection points of the the two perp bisectors
	// This is the center point of the circle that shares all three points
	double xint = (b2 - b1) / (slope1 - slope2);
	double yint = slope1 * xint + b1;

	// Compute the radius of the circle from the center point to any point - p1 used
	double r = sqrt((xint-p1.get_x())*(xint-p1.get_x())+(yint - p1.get_y())*(yint - p1.get_y()));

	// plot: third point, center point, and the circle
	cwin << p3 << Point(xint, yint) << Circle(Point(xint, yint), r);

	return 0;
}