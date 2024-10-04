// P59.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/**
	Computes and returns the distance between two points
	@param x1 x coordinate of first point
	@param y1 y coordinate of first point
	@param x2 x coordinate of second point
	@param y2 y coordinate of second point
	@return distance between the two points
*/
double distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main()
{
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	cout << "x and y coordinates of first point: ";
	cin >> x1 >> y1;

	cout << "x and y coordinates of second point: ";
	cin >> x2 >> y2;

	cout << "Point 1: (" << x1 << "," << y1 << ")\n"
		 << "Point 2: (" << x2 << "," << y2 << ")\n\n"
		 << "Distance between point 1 and point 2: " << distance(x1, y1, x2, y2) << endl;
	return 0;
}

