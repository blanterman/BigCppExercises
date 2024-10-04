/*
	Exercise P7.16. Draw a picture of the "four-leaved rose" whose equation in 
	polar coordinates is r = cos(2*theta), 0 <= theta <= 2*pi. Let theta go 
	from 0 to 2*pi in 100 steps. Each time, compute r and then compute the 
	(x, y) coordinates from the polar coordinates by using the formula 
	x = rcos(theta) 
	y = rsin(theta).  
	You will get extra credit if you can vary the number of petals. 
*/
#include "ccc_win.h"

const double PI = 3.14159265358979323;

int ccc_win_main()
{
	//Extra credit, vary the multiplier and the thetaMax to get a different
	// number of petals.
	double multiplier = 2;
	double numPoints = 1000.0;
	double theta = 0;
	double r = 0;
	double thetaMax = 2 * PI;
	double delta = (thetaMax - theta) / numPoints;
	double x = 0;
	double y = 0;

	r = cos(multiplier * theta);
	
	x = r * cos(theta);
	y = r * sin(theta);
	Point P1(x, y);
	cwin.coord(-2, 2, 2, -2);

	for(int i = 0; i < numPoints; i++)
	{
		theta += delta;
		r = cos(multiplier * theta);
		x = r * cos(theta);
		y = r * sin(theta);
		Point P2(x, y);
		Line L1(P1, P2);
		cwin << L1;
		P1 = P2;
	}
	return 0;
}