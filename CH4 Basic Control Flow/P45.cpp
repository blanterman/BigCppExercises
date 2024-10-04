#include "ccc_win.h"
#include <string>

// This program uses linear algebra techniques to find the intersection of two line segments

using namespace std;

int ccc_win_main()
{
	// Gets 2 points from the user to define line segment 1
	Point a = cwin.get_mouse("Select endpoints for first segment");
	cwin << a; // user feedback
	Point b = cwin.get_mouse("Select endpoints for first segment");
	cwin << b << Line(a, b); // user feedback

	// Gets 2 points from the user to define line 2
	Point c = cwin.get_mouse("Select endpoints for second segment");
	cwin << c; // user feedback
	Point d = cwin.get_mouse("Select endpoints for second segment");
	cwin << d << Line(c, d); // user feedback

	/* Defines entries in the A matrix of a system of linear equations
	   that has been worked to the Ax=b form. x here is a vector that
	   we want to solve for x = <t, s>*/
	double A = b.get_x() - a.get_x();
	double B = c.get_x() - d.get_x();
	double C = b.get_y() - a.get_y();
	double D = c.get_y() - d.get_y();

	// Defines entries in the b vector shown above
	double b1 = c.get_x() - a.get_x();
	double b2 = c.get_y() - a.get_y();

	// compute the determinant of the A matrix to determine invertibility.
	double detA = A * D - (B * C);

	if(detA == 0) // If determinant is 0, there is no solution (ie lines parallel)
	{
		Message m1(Point(-8.0, 8.0), "segments are parallel and dont intersect");
		cwin << m1;
		return 0; // stop the program
	}

	// comput entries in the A inverse matrix
	double invA = D / detA;
	double invB = -B / detA;
	double invC = -C / detA;
	double invD = A / detA;

	// solve for the entries in the x vector shown above
	double tsol = invA * b1 + invB * b2;
	double ssol = invC * b1 + invD * b2; // ssol is never used but could be used 
	                                     // with points of line 2 to get same point

	// if t < 0 or t > 1 the segments wont intersect.
	if(tsol < 0.0 || tsol > 1.0)
		cwin << Message(Point(0.0, 0.0), "The line segments you selected do not intersect");
	else
	{
		// use the solution in the vector equation of the line to get the coordinates of the solution
		double solx = (1 - tsol) * a.get_x() + tsol * b.get_x();
		double soly = (1 - tsol) * a.get_y() + tsol * b.get_y();

		Point sol(solx, soly);

		cwin << sol << Line(sol, b) << Line(sol, d);
		cwin << Message(sol, "Intersection");
	}

	return 0;
}