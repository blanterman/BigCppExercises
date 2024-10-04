// P26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double side1 = 0, side2 = 0, perimeter = 0, area = 0, diag = 0;
	
	cout << "Please provide me with the lengths of the sides of a rectangle: \n";
	
	cin >> side1 >> side2;

	perimeter = 2 * (side1 + side2);
	area = side1 * side2;
	diag = sqrt((side1 * side1) + (side2 * side2));

	cout << "The perimeter is: " << perimeter << "\n"
		 << "The area is: " << area << "\n"
		 << "The length of the diagonal is: " << diag << "\n";

	return 0;
}

