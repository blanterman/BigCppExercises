// P425.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	bool more = true;
	double x = 0, y = 0, x_bar = 0, y_bar = 0, sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0, 
		   count = 0, m = 0, b = 0;

	//I am not doing any input checking on this program
	while (more)
	{
		cout << "Enter a point, enter 99 99 to show you are done: ";
		cin >> x >> y;
		if (x == 99.0 && y == 99.0)
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

	cout << "The equation of the least squared regression line for your points is:\n"
		 << "y = " << m << "x" << " + " << b << ".\n";

	return 0;
}

