// P425.cpp : Defines the entry point for the console application.
//

#include "ccc_win.h"
#include <iostream>

using namespace std;

int ccc_win_main()
{
	bool more = true;
	double x = 0, y = 0, x_bar = 0, y_bar = 0, sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0, 
		   count = 0, m = 0, b = 0, x_l = -10.0, x_r = 10.0, y_l = 0.0, y_r = 0.0;
	// Draw the finish box
	Point p1(9.0, -9.0);
	Point p2 = p1;
	p2.move(1.0, 0.0);
	Line l1(p1, p2);
	Line l2 = l1;
	l2.move(0.0, -1.0);
	Point p3 = p1;
	p3.move(0.0, -1.0);
	Line l3(p1, p3);
	Line l4 = l3;
	l4.move(1.0, 0.0);
	cwin << l1 << l2 << l3 << l4;

	//I am not doing any input checking on this program
	while (more)
	{
		Point p4 = cwin.get_mouse("Enter a point, click in the box when you are done");
		cwin << p4; // user feedback
		x = p4.get_x();
		y = p4.get_y();
		if (x <= 10.0 && x >=9.0 && y >= -10.0 && y <= -9.0)
		{
			more = false;
		}
		else
		{
			count++;
			sum_x += x;
			sum_y += y;
			sum_xy += x * y;
			sum_xx += x * x;
		}
	}

	x_bar = sum_x / count;
	y_bar = sum_y / count;
	m = (sum_xy - (count * x_bar * y_bar)) / (sum_xx - (count * x_bar * x_bar));
	b = y_bar - m * x_bar;

	y_l = m * x_l + b;
	y_r = m * x_r + b;

	Point p5(x_l, y_l);
	Point p6(x_r, y_r);
	Line l5(p5, p6);
	cwin << l5;

	return 0;
}

