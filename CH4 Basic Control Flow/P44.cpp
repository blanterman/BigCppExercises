// P44.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793238;

int main()
{
	double a = 0, b = 0, c = 0, q = 0, r = 0, sgn_r = 0, t = 0, u = 0, v = 0,
		   x1 = 0, x2 = 0, x3 = 0;
	cout << "This program will find the solutions to the cubic polynomial,\n"
		 << "x^3 + ax^2 + bx + c = 0. Please provide a, b, and c: ";
	cin >> a >> b >> c;
	q = (a * a - 3.0 * b) / 9.0;
	r = (2 * pow(a,3.0) - 9.0 * a * b + 27.0 * c) / 54.0;

	if ((r*r) < pow(q,3))
	{
		t = acos(r / sqrt(pow(q,3)));
		x1 = -2 * sqrt(q) * cos(t / 3) - (a / 3.0);
		x2 = -2 * sqrt(q) * cos((t + 2 * PI) / 3.0) - (a / 3.0);
		x3 = -2 * sqrt(q) * cos((t - 2 * PI) / 3.0) - (a / 3.0);

		cout << "There are 3  real solutions:\n" << x1 << " and " << x2 << " and " << x3 << ".\n";
	}
	else
	{
		sgn_r = r >= 0 ? 1.0 : -1.0;
		u = -sgn_r * pow(abs(r) + sqrt(r * r - pow(q,3.0)),(1.0 / 3.0));
		v = u!=0.0 ? q / u : 0.0;
		x1 = u + v - (a / 3.0);

		cout << "There is only 1 real solution: \n"
			 << x1 << "\n";
	}
	return 0;
}

