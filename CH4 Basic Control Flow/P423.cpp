#include "ccc_win.h"
#include <string>

using namespace std;

int ccc_win_main()
{
	int numbars = cwin.get_int("How Many Bars?");	
	double x = 0.0, width = 2.0, maxval = 0.0;
	cwin.coord(x, 120, width * numbars, 0.0);
	for(int i = 0; i < numbars; i++)
	{
		string message = "What is the value of bar " + to_string(static_cast<long long>(i + 1));
		double val = cwin.get_double(message);
		if(val > maxval)
			maxval = val;
		Point p1(x, 0.0);
		Point p2 = p1;
		p2.move(0.0, val);
		Line l1(p1, p2);
		Line l2 = l1;
		l2.move(width, 0.0);
		Point p3 = p1;
		p3.move(width, 0.0);
		Line l3(p1, p3);
		Line l4 = l3;
		l4.move(0.0, val);
		cwin << l1 << l2 << l3 << l4;
		x += width;
	}
	cwin.coord(x, maxval + 0.5, width * numbars, 0.0);
	return 0;
}