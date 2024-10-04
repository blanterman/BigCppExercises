/*	Exercise P9.12. Enhance the Polygon class of Exercise P9.11 by adding 
member functions

	double Polygon::perimeter() const

and

	double Polygon::area() const

that compute the perimeter and the area of a polygon. To compute the perimeter, 
compute the distance between adjacent points, and total up the distances.

The area of a polygon with corners (x_0,y_0),...,(x_n-1, y_n-1) is

(1/2) * abs(x_0 * y_1 + x_1 * y_2 + ... + x_n-1 * y_0 
		  - y_0 * x_1 - y_1 * x_2 - ... - y_n-1 * x_0)

As test cases, compute the perimeter and area of a rectangle and of a regular hexagon.

Bryson Lanterman 20180712
*/

#include "P911-P913_Polygon.h"

const double WIND_H_W = 21.0;
const double HEXAGON_HEIGHT = sqrt(3.0) * 5;
const double ALLOWED_DIFFERENCE = 1E-13;

/**
	checks whether two floating point values are equal to a reasonable degree
	@param val1 floating point value
	@param val2 floating point value
	@return equal returns true if val1 and val2 are equal to a reasonable degree
*/
bool approx_equal(double val1, double val2)
{
	if(abs(val1 - val2) <= ALLOWED_DIFFERENCE)
		return true;
	else
		return false;
}


///*** Test Harness for the Polygon Class ***///

int ccc_win_main()
{
	string perimeterString;
	string areaString;
	double testPerimeter = 0.0;
	double testArea = 0.0;
	string perimeterTestResult;
	string areaTestResult;

	// Resize/Center the display area
	cwin.coord(-1.0, 21.0, 21.0, -1.0);

	//
	// Testing Perimeter and Area with a rectangle
	// Perimeter should be 50.0
	// Area should be 150
	//

	// Construct and plot a rectangle object
	Polygon rectangle;
	rectangle.add_point(Point(0.0, 0.0));
	rectangle.add_point(Point(0.0, 15.0));
	rectangle.add_point(Point(10.0, 15.0));
	rectangle.add_point(Point(10.0, 0.0));
	rectangle.plot();

	// Get the Perimeter of the rectangle, cast as string and make a message to display
	double rectanglePerimeter = rectangle.perimeter();
	perimeterString = "Perimeter: " + to_string(static_cast<long double>(rectanglePerimeter));
	Message m1(Point(0.0, 0.0), perimeterString);

	// Get the Area of the rectangle, cast as string and make a message to display
	double rectangleArea = rectangle.area();
	areaString = "Area: " + to_string(static_cast<long double>(rectangleArea));
	Message m2(Point(5.0, 7.5), areaString);

	//Set the validation values for perimeter and area
	testPerimeter = 50.0;
	testArea = 150.0;

	// Perform the perimeter test and set result string, then construct a message to display
	//result string.
	if (rectanglePerimeter == testPerimeter) // test passed
	{
		perimeterTestResult = "Perimeter Test Passed";
	}
	else // test failed
	{
		perimeterTestResult = "Perimeter Test Failed";
	}
	Message m3(Point(5.0, 0.0), perimeterTestResult);

	// Perform the area test and set result string, then construct a message to display
	//result string.
	if (rectangleArea == testArea) // test passed
	{
		areaTestResult = "Area Test Passed";
	}
	else // test failed
	{
		areaTestResult = "Area Test Failed";
	}
	Message m4(Point(5.0, 5.5), areaTestResult);

	// Display messages
	cwin << m1 << m2 << m3 << m4;

	//
	// Testing Perimeter with a hexagon
	// Perimeter should be 30.0
	//

	// Construct and plot an hexagon object
	Polygon hexagon;
	hexagon.add_point(Point(12.5, 0.0));
	hexagon.add_point(Point(10.0, HEXAGON_HEIGHT / 2.0));
	hexagon.add_point(Point(12.5, HEXAGON_HEIGHT));
	hexagon.add_point(Point(17.5, HEXAGON_HEIGHT));
	hexagon.add_point(Point(20.0, HEXAGON_HEIGHT / 2.0));
	hexagon.add_point(Point(17.5, 0.0));
	hexagon.plot();

	// Get the Perimeter of the hexagon, cast as string and make a message to display
	double hexagonPerimeter = hexagon.perimeter();
	perimeterString = "Perimeter: " + to_string(static_cast<long double>(hexagonPerimeter));
	Message m5(Point(10.0, 0.0), perimeterString);

	// Get the Area of the hexagon, cast as string and make a message to display
	double hexagonArea = hexagon.area();
	areaString = "Area: " + to_string(static_cast<long double>(hexagonArea));
	Message m6(Point(15.0, 7.5), areaString);

	//Set the validation values for perimeter and area
	testPerimeter = 30.0;
	testArea = 37.5 * sqrt(3.0);

	// Perform the perimeter test and set result string, then construct a message to display
	//result string.
	if (hexagonPerimeter == testPerimeter) // test passed
	{
		perimeterTestResult = "Perimeter Test Passed";
	}
	else // test failed
	{
		perimeterTestResult = "Perimeter Test Failed";
	}
	Message m7(Point(15.0, 0.0), perimeterTestResult);

	// Perform the area test and set result string, then construct a message to display
	//result string.
	if (approx_equal(hexagonArea, testArea)) // test passed
	{
		areaTestResult = "Area Test Passed";
	}
	else // test failed
	{
		areaTestResult = "Area Test Failed";
	}
	Message m8(Point(15.0, 5.5), areaTestResult);

	//Display messages
	cwin << m5 << m6 << m7 << m8;

	return 0;
}