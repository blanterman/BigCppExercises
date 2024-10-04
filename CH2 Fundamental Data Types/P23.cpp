// P23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int x, y;
	int width = 12;
	cout << "please give me two of your best integers: x y \n";
	cin >> x >> y;

	int sum = x + y;
	int product = x * y;
	int difference = x - y;
	double average = sum / 2.0;
	int distance = fabs(static_cast<double>(x) - static_cast<double>(y));
	int maximum = max(x,y);
	int minimum = min(x,y);

	cout << fixed << setprecision(2);
	cout << x << " and " << y << "\n";
	cout << setw(width) << "sum" << "|" << setw(width) << sum << "\n";
	cout << setw(width) << "difference" << "|" << setw(width) << difference << "\n";
	cout << setw(width) << "product" << "|" << setw(width) << product << "\n";
	cout << setw(width) << "average" << "|" << setw(width) << average << "\n";
	cout << setw(width) << "distance" << "|" << setw(width) << distance << "\n";
	cout << setw(width) << "maximum" << "|" << setw(width) << maximum << "\n";
	cout << setw(width) << "minimum" << "|" << setw(width) << minimum << "\n";

	return 0;
}

