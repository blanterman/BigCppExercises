// P28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	const double PI = 3.14159265358979323;
	const double DEG2RAD = PI/180.0;
    
	double side_a = 0, side_b = 0, side_c = 0,
		   angl_A = 0, angl_B = 0, angl_C = 0;

	cout << "Give length of a side of a triangle and the sizes of the two adjacent angles to the side:\n";
	cin >> side_a >> angl_C >> angl_B;

	angl_A = 180.0 - angl_B - angl_C;
	side_b = (side_a * sin(angl_B * DEG2RAD))/sin(angl_A * DEG2RAD);
	side_c = (side_a * sin(angl_C * DEG2RAD))/sin(angl_A * DEG2RAD);

	cout << "Third Angle: " << angl_A << " degrees.\n"
		 << "Two other sides: " << side_b << " and " << side_c << "\n";
	return 0;
}

