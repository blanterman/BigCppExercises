#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	const double EPSILON = 1E-14;
	double a = 0.0, xnew = 0.0, xold = 0.0, n = 0.0;

	cout << "Please enter a number: ";
	cin >> a;

	cout << "Please enter the root number you wish to find: ";
	cin >> n;

	xnew = a;

	do
	{
		xold = xnew;
		xnew = xold - (pow(xold, n) - a) / (n * pow(xold, n - 1));
	}
	while(fabs(xnew - xold) > EPSILON);

	string ending;

	if (n == 2)
	{
		ending = "nd";
	}
	else if (n == 3)
	{
		ending = "rd";
	}
	else
	{
		ending = "th";
	}

	cout << "The " << n << ending << " root of " << a << " is: " <<  xnew << "\n";

	return 0;
}