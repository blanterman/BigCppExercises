#include "ccc_win.h"

int ccc_win_main()
{
	double r = 1.0, del = 0.1;
	double d = (r + del) * 2.0;
	Circle c1(Point(-d,1.0), r);
	Circle c2 = c1;
	c2.move(d, 0.0);
	Circle c3 = c2;
	c3.move(d, 0.0);

	Circle c4 = c1;
	c4.move(d/2.0,-r);
	Circle c5 = c2;
	c5.move(d/2.0,-r);

	cwin << c1 << c2 << c3 << c4 << c5;
	return 0;
}