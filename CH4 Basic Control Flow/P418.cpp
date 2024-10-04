// P418.cpp : Defines the entry point for the console application.
//

#include "ccc_win.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

/**
	draws a grid that is 10 x 10
*/
void draw_grid()
{
	Point p1(-10.0, 10.0);
	Point p2 = p1;
	p2.move(20.0, 0.0);
	Line l1(p1, p2);
	cwin << l1;
	for(int i = 0; i < 10; i++)
	{
		l1.move(0.0, -2.0);
		cwin << l1;
	}

	Point p3 = p1;
	p3.move(0.0, -20.0);
	Line l2(p1, p3);
	cwin << l2;
	for(int i = 0; i < 10; i++)
	{
		l2.move(2.0, 0.0);
		cwin << l2;
	}
}

int ccc_win_main()
{
	cwin.coord(-25.0, 25.0, 25.0, -25.0);
	draw_grid();
	int iter = 100;
	double dist = 0.0, dir = 0.0, x = 0.0, y = 0.0;
	srand(time(NULL));
	Point p1(x,y);
	cwin << p1;
	Point p2;
	for (int i = 0; i < iter; i++)
	{
		dir = rand() % 4;
		if (dir == 0)
			x += 2.0;
		if (dir == 1)
			x -= 2.0;
		if (dir == 2)
			y += 2.0;
		if (dir == 3)
			y -= 2.0;
		p2 = Point(x, y);
		cwin << p2 << Message(p2, i);
	}

	cwin << Circle(p2, 1.0);
	dist = sqrt(x * x + y * y); 
	cwin << Message(Point(0.0, -1.0), dist);

	return 0;
}

