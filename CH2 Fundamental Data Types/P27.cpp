// P27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	const double PI = 3.14159265358979323;
	const double deg2rad = PI / 180.0;
	const double rad2deg = 180.0 / PI;

	double side1 = 0, side2 = 0, side3 = 0, 
		   angle1 = 0, angle2 = 0, angle3 = 0;
	
	cout << "Give me two sides of a triangle and the size of the angle (in degrees) between them, NOW!\n";

	cin >> side1 >> side2 >> angle3;

	side3 = sqrt((side1 * side1) + (side2 * side2) - (2 * side1 * side2 * cos(angle3 * deg2rad)));
	angle1 = acos(((side1 * side1) - (side2 * side2) - (side3 * side3))/(-2 * side2 * side3)) * rad2deg;
	angle2 = acos(((side2 * side2) - (side1 * side1) - (side3 * side3))/(-2 * side1 * side3)) * rad2deg;

	cout << "The length of the third side is: " << side3 << "\n"
		 << "The other two angles are: " << angle1 << " degrees and " << angle2 << " degrees\n";


	return 0;
}

