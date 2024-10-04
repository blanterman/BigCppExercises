// P41.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double a = 0, b = 0, c = 0,
		   disc = 0, x_plus = 0, x_minus = 0;
	cout << "Please Provide the coefficients of the quadratic: a, b, and c: ";
	cin >> a >> b >> c;
	disc = b * b - 4 * a * c;
	if (disc < 0)
	{
		cout << "Error: Non-real Result\n";
		return 1;
	}
	else
	{
		x_plus = (-b + sqrt(disc))/(2 * a);
		x_minus = (-b - sqrt(disc))/(2 * a);
		cout << "The solutions are: " << x_plus << " and " << x_minus << "\n";
	}
	return 0;
}

