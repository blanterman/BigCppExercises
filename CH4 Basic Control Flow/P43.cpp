// P43.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double a = 0, b = 0, c = 0,
		   disc = 0, x1 = 0, x2 = 0,
		   sgn_b = 0, q = 0;
	cout << "Provide coefficients a, b, and c of a quadratic equation: ";
	cin >> a >> b >> c;

	if (cin.fail())
	{
		cout << "Error: Bad input values.\n";
		return 1;
	}
	else
	{
		disc = (b * b) - (4 * a * c);
		if (disc < 0)
		{
			cout << "Error: Non-real Result\n";
			return 2;
		}
		else
		{
			x1 = (-b + sqrt(disc))/(2 * a);
			x2 = (-b - sqrt(disc))/(2 * a);

			cout << "Are these Solutions: " << x1 << " and " << x2 << "\n";

			sgn_b = b >= 0 ? 1 : -1;
			q = -0.5 * (b + sgn_b * sqrt(disc));
			x1 = q / a;
			x2 = c / q;
			
			cout << "more accurate than these solutions: " << x1 << " and " << x2 << "?\n";
		}
	}

	return 0;
}

