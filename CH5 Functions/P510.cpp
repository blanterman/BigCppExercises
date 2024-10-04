// P510.cpp : Defines the entry point for the console application.
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

/**
	Determines if a given point is inside a given circle
	@param xC x-coordinate of the center of the circle
	@param yC y-coordinate of the center of the circle
	@param r radius of the circle
	@param x x-coordinate of point
	@param y y-coordinate of point
	@return boolean true if point lies in the circle
*/
bool is_inside(double xC, double yC, double r, double x, double y)
{
	return (distance(xC, yC, x, y)) <= r;
}

int main()
{
	double xC = 0, yC = 0, r = 0, x = 0, y = 0;
	
	cout << "x and y coordinate of center of circle and radius, xC yC r: ";
	cin >> xC >> yC >> r;

	cout << "x and y coordinates of any point: ";
	cin >> x >> y;

	if (is_inside(xC, yC, r, x, y))
		cout << "Point (" << x << "," << y << ")" << " IS in the circle!" << endl;
	else
		cout << "Point (" << x << "," << y << ")" << " is NOT in the circle!" << endl;

	return 0;
}

