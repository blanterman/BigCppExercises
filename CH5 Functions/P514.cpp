// P514.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/**
	Computes the Julian Day number for a given date
	@param day integer day number of a month
	@param month integer month number of a year
	@param year integer year number
	@return jul long julian day number
*/
long julian(int year, int month, int day)
{
	long jd = 0, jm = 0, jy = 0;
	jd = day;
	jm = month;
	jy = year;

	if (jy < 0)
		jy++;
	
	if (jm > 2)
		jm++;
	else
	{
		jm = jm + 13;
		jy--;
	}
	
	long jul = floor(365.25 * jy) + floor(30.6001 * jm) + jd + 1720995.0;

	if (jy < 1582 && jm < 10 && jd < 15)
		return jul;
	else
	{
		int ja = 0.01 * jy;
		jul = jul + 2 - ja + 0.25 * ja;
		return jul;
	}
}

int main()
{
	int day = 0, month = 0, year = 0;
	cout << "Day: ";
	cin >> day;
	cout << "Month: ";
	cin >> month;
	cout << "Year: ";
	cin >> year;

	long jul = julian(year, month, day);
	long julTdy = julian(2017, 7, 5);
	cout << "Days since that date: " << julTdy - jul << endl;
	return 0;
}

