// P420.cpp : Defines the entry point for the console application.
//

#include "ccc_win.h"
#include <iostream>
#include <cmath>


using namespace std;

const double delta_t = 0.01;
const double g = 9.8;
const double PI = 3.14159265358979;
const double d_2_r = PI / 180.0;

int ccc_win_main()
{
	double init_ht = 0.1;
	double sx = 0, sy = 0, v = 0, vx = 0, vy = 0, t = 0, alpha = 0;
	int count = 0;	

	v = cwin.get_double("What is the initial velocity?");
	alpha = cwin.get_double("What is the initial angle?");
		
	sy = init_ht;
	vx = v * cos(alpha * d_2_r);
	vy = v * sin(alpha * d_2_r);
	cwin.coord(0,20,20,0);
	while (sy > 0)
	{
		if (count % static_cast<int>(0.1 / delta_t) == 0)
		{
			Point p1(sx, sy);
			cwin << p1 << Message(p1, sy);
		}
		sx = sx + vx * delta_t;
		sy = sy + vy * delta_t;
		vy = vy - g * delta_t;
		count++;
				
	}
	Point p1(sx, sy);
			cwin << p1;
	return 0;
}

