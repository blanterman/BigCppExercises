#include "ccc_win.h"

int ccc_win_main()
{
	Point cent1 = cwin.get_mouse("Click on the center of the first Circle");
	cwin << cent1; // User feedback
	double radc1 = cwin.get_double("What is the radius of the first circle?");
	Circle c1(cent1, radc1);
	cwin << c1; // user feedback

	Point cent2 = cwin.get_mouse("Click on the center of the second Circle");
	cwin << cent2; // User feedback
	double radc2 = cwin.get_double("What is the radius of the second circle?");
	Circle c2(cent2, radc2);
	cwin << c2; // user feedback

	double dist = sqrt((cent1.get_y() - cent2.get_y()) * (cent1.get_y() - cent2.get_y()) + (cent1.get_x() - cent2.get_x()) * (cent1.get_x() - cent2.get_x()));
	double intlim = radc1 + radc2;

	if(dist <= intlim)
	{
		cwin << Message(cent1,"Circles Intersect");
	}
	else
	{
		cwin << Message(cent2,"Circles Do Not Intersect");
	}

	return 0;
}