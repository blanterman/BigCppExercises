// P210.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double gals_in_tank = 0, mpg = 0, prc_per_gal = 0;
	double dist = 0, prc_per_hun = 0;

	cout << "How many gallons of gas are in the tank?\n";
	cin >> gals_in_tank;
	cout << "What is the fuel efficiency in mpg?\n";
	cin >> mpg;
	cout << "What is the price per gallon?\n";
	cin >> prc_per_gal;

	dist = gals_in_tank * mpg;
	prc_per_hun = 100.0 * (1.0 / mpg) * prc_per_gal;

	cout << fixed << setprecision(2);
	cout << "Your car can travel " << dist << " miles with that amount of gas in the tank.\n"
		 << "It costs you $" << prc_per_hun << " to go 100 miles.\n";

	return 0;
}

