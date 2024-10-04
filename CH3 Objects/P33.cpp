#include "ccc_win.h"

int ccc_win_main()
{
	Point cp = cwin.get_mouse("Click on the center of the circle");
	cwin << cp;
	Point rp = cwin.get_mouse("Click on the boundary of the circle");
	
	double r = sqrt((rp.get_x() - cp.get_x()) * (rp.get_x() - cp.get_x()) + (rp.get_y() - cp.get_y()) * (rp.get_y() - cp.get_y()));

	cwin << Circle(cp, r);
	return 0;
}