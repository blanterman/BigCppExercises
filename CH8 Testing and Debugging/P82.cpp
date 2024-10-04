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
#include <string>

using namespace std;

const double EPSILON = 10E-6;

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

/* Exercise P8.2. Write a simple test harness for the arcsin function that 
reads floating-point numbers from cin and computes their arc sines, until the
end of the input is reached. Then run that program and verify its outputs 
against the arc sine function of a scientific calculator.
*/

/* Test Harness */
int main()
{
	double x;
	double output;
	while(cin >> x)
	{
		output = arcsin(x);
		cout << "arcsin(" << x << ") = " << output << "\n";
	}
	return 0;
}