// P25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	const double PI = 3.14159265358979323;
	double radius = 0;

	cout << "Please give me a wonderful radius value.\n";
	cin >> radius;

	double area = PI * radius * radius;
	double circumference = 2.0 * PI * radius;
	double volume = (4.0/3.0) * PI * pow(radius,3);
	double surf_area = 4 * area;

	cout << "The area of the circle with that radius: " << area << "\n";
	cout << "The circumference of the circle with that radius: " << circumference << "\n";
	cout << "The volume of the sphere with that radius: " << volume << "\n";
	cout << "The surface area of the sphere with that radius: " << surf_area << "\n";
	return 0;
}

