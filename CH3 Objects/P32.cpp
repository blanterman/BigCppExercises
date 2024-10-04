#include "ccc_win.h"

int ccc_win_main()
{
	Point p1 = cwin.get_mouse("Please click on the first point");
	cwin << p1;
	Point p2 = cwin.get_mouse("Please click on the second point");
	cwin << p2;
	Point p3 = cwin.get_mouse("Please click on the third point");
	cwin << p3;
	Line l1(p1, p2);
	Line l2(p2, p3);
	Line l3(p1, p3);
	cwin << l1 << l2 << l3;
	return 0;
}