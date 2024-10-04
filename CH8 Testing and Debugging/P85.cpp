/* Exercise P8.1 The arc sine function is the inverse of the sine function. 
That is,

y = arcsin(x)

if

x = sin(y)

for example,

arcsin(0) = 0
arcsin(0.5) = pi/6
arcsin(sqrt(2)/2) = pi/4
arcsin(sqrt(3)/2) = pi/3
arcsin(1) = pi/2
arcsin(-1) = -pi/2

The arc sine is defined only for values between -1 and 1. This function is also
often called sin^-1(x). Note, however, that it is not at all the same as 
1/sin(x). There is no C++ standard library function to compute the arc sine. 
For this exercise, write a C++ function that computes the arc sine from its 
Taylor series expansion

arcsin(x) = x + ((x^3)/3!) + ((x^5)*(3^2)/5!) + ((x^7)*(3^2)*(5^2)/7! + ...

You should compute the sum until a new term is < 10^-6. This function will be 
used in subsequent exercises.

Bryson Lanterman 20180320
*/
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const double EPSILON = 10E-16;	// This value was made a lot smaller for the 
								//test harness because of the approx_equal
								//function. The epsilon in that function
								//could have been changed too to the same effect

/**
	Computes the arc sine of an input using the Taylor Series Expansion of 
	arcsin(x) given above.
	@param x double input between -1 and 1
	@return arcsinx double arc sine value of x.
*/
double arcsin(double x)
{
	if (x < -1.0 || x > 1.0)
	{
		cout << "Invalid input\n";
		return -1.0;
	}
	double arcsinx = 0;
	int n = 1;
	double summand = x;
	while(abs(summand) > EPSILON)
	{
		arcsinx += summand;
		summand *= (x * x * (2 * n - 1) * (2 * n - 1)) / ((2 * n) * (2 * n + 1));
		n++;
	}
	return arcsinx;
}

/* Exercise P8.5. Write a test harness that automatically tests the validity of
the arcsin function by verifying that sin(arcsin()) is approximately equal to 
x. Test with 100 random inputs.
*/

/**
	Tests whether two floating-point numbers are approximately equal.
	@param x a floating-point number
	@param y another floating-point number
	@return true if x and y are approximately equal
*/
bool approx_equal(double x, double y)
{
	const double EPSILON = 1E-14;
	if (x == 0) return fabs(y) <= EPSILON;
	if (y == 0) return fabs(x) <= EPSILON;
	cout << fabs(x - y) / max(fabs(x), fabs(y)) << "\n";
	return fabs(x - y) / max(fabs(x), fabs(y)) <= EPSILON;
}

/* Test Harness */
int main()
{
	double x;
	double val1;
	double maybeX;
	double lowBound = -1.0;
	double upBound = 1.0;
	srand(time(NULL));
	for(int i = 0; i < 100; i++)
	{
		x = lowBound + (upBound - lowBound) * rand() * (1.0 / RAND_MAX);
		val1 = arcsin(x);
		maybeX = sin(val1);
		if (!approx_equal(x, maybeX))
			cout << "Test Failed. ";
		else
			cout << "Test Passed. ";
		cout << "arcsin(" << x << ") = " << val1 << "\n";
	}
	return 0;
}