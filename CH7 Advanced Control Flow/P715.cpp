/*
	Exercise P7.15. It is easy and fun to draw graphs of curves with the C++
	graphics library. simply draw 100 line segments joining the points 
	(x, f(x)) and (x+d, f(x+d)), where x ranges from xmin to xmax and 
	d = (xmax - xmin)/100. Draw the curve f(x) = x^3/100 - x + 10, where x 
	ranges from -10 to 10.
*/
#include "ccc_win.h"

int ccc_win_main()
{
	double numPoints = 100.0;
	double x = -10.0;
	double y = 0;
	double xmax = 10.0;
	double delta = (xmax - x) / numPoints;

	y = (((x * x * x) / 100.0) - x) + 10.0;
	Point P1(x, y);
	cwin.coord(-10, 15, 10, -15);

	for(int i = 0; i < numPoints; i++)
	{
		x += delta;
		y = (((x * x * x) / 100.0) - x) + 10.0;
		Point P2(x, y);
		Line L1(P1, P2);
		cwin << L1;
		P1 = P2;
	}
	return 0;
}