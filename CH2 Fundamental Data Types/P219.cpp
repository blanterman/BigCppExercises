// P219.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int time1 = 0, time2 = 0, hrs = 0, mins = 0;
	double dbl_time1 = 0, dbl_time2 = 0, frac_of_hour = 0,
		   time_bet = 0;

	cout << "Please enter the first time: ";
	cin >> time1;
	cout << "please enter the second time: ";
	cin >> time2;

	//Put the time1 into decimal eg 930 = 9.50
	hrs = time1 / 100;
	mins = time1 % 100;
	frac_of_hour = mins / 60.0;
	dbl_time1 = hrs + frac_of_hour;

	//Put the time2 into decimal eg 930 = 9.50
	hrs = time2 / 100;
	mins = time2 % 100;
	frac_of_hour = mins / 60.0;
	dbl_time2 = hrs + frac_of_hour;

	// Get the amount of time between the two times. This number will never be negative
	time_bet =  24.00 + (dbl_time2 - dbl_time1);

	hrs = static_cast<int>(floor(time_bet)) % 24;
	mins = floor((time_bet - floor(time_bet)) * 60 + 0.5); // Add the 0.5 for round error

	cout << hrs << " hours " << mins << " minutes.\n";
	return 0;
}

