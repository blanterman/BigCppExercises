// P24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	const double MILES_PER_METER = 0.000621504039776;
	const double FEET_PER_METER = 3.27868852459;
	const double INCHES_PER_METER = 39.3700787402;
	
	double user_meas = 0;

	cout << "Please provide me with a measurement in meters.\n";
	cin >> user_meas;

	cout << "Your measurement in meters: " << user_meas << " meters. \n"
		 << "Your measurement in miles: " << user_meas * MILES_PER_METER << " miles. \n"
		 << "Your measurement in feet: " << user_meas * FEET_PER_METER << " feet. \n"
		 << "Your measurement in inches: " << user_meas * INCHES_PER_METER << " inches. \n";

	return 0;
}

