#include "ccc_win.h"

int ccc_win_main()
{
	Point p1(0.0, 0.0);
	Point p2 = p1;
	p2.move(1.0, 0.0);
	Point p3 = p1;
	p3.move(0.0, 1.0);

	Line l1(p1, p2);
	Line l2 = l1;
	l2.move(0.0, 1.0);

	Line l3(p1, p3);
	Line l4 = l3;
	l4.move(1.0, 0.0);

	cwin << l1 << l2 << l3 << l4;

	bool cont = true;

	while(cont)
	{
		cwin << l1 << l2 << l3 << l4;
		Point p4 = cwin.get_mouse("Please click inside the box");

		if(p4.get_x() >= 0.0 && p4.get_x() <= 1.0 && p4.get_y() >= 0.0 && p4.get_y() <= 1.0)
		{
			cwin.clear();
			cwin << l1 << l2 << l3 << l4 << p4;
			cwin << Message(Point(0.0, 0.0), "Congratulations");
			cont = false;
		}
		else
		{
			cwin << Message(Point(-8.0, 8.0), "You Missed, try again");
		}
	}
	return 0;
}