#include "ccc_win.h"
/*
	Asks for 2 points to be clicked, then draws a line between them.
	Display a message of the length of the line at the center point of the 
	line.
*/

int ccc_win_main()
{
	// Get first point
	Point p1 = cwin.get_mouse("Click 2 points");	
	cwin << p1;  // User feedback
	// Get second point
	Point p2 = cwin.get_mouse("Click 2 points");

	// Compute length of line
	double length = sqrt((p2.get_y() - p1.get_y()) * (p2.get_y() - p1.get_y()) + (p2.get_x() - p1.get_x()) * (p2.get_x() - p1.get_x()));

	// Compute and get center point
	Point p3 = p1;
	p3.move((p2.get_x() - p1.get_x())/2.0, (p2.get_y() - p1.get_y())/2.0);

	// Display points line and message
	cwin << p2 << Line(p1, p2) << p3 << Message(p3, length);
	return 0;
}