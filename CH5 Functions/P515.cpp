// P515.cpp : Defines the entry point for the console application.
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

/**
	Converts a julian day to the date of that day
	@param jul long integer julian day
	@param year integer year number
	@param month integer month number 
	@param day integer day number
*/
void jul_to_date(long jul, int& year, int& month, int& day)
{
	if (jul >= 2299161)
	{
		long jalpha = ((jul - 1867216) - 0.25) / 36524.25;
		jul = jul + 1 + jalpha - 0.25 * jalpha;
	}

	long jb = jul + 1524;
	long jc = 6680.0 + (jb - 2439870 - 122.1)/365.25;
	long jd = 365 * jc + (0.25 * jc);
	int je = (jb - jd)/30.6001;

	day = jb - jd - (long)(30.6001 * je);
	month = je - 1;
	year = (int)(jc - 4715);

	if (month > 12)
		month = month - 12;
	if (month > 2)
		year--;
	if (year < 0)
		year--;
}

int main()
{
	long n = 0, jul = 0;
	int day = 0, month = 0, year = 0;
	
	cout << "Day: ";
	cin >> day;
	cout << "Month: ";
	cin >> month;
	cout << "Year: ";
	cin >> year;
	cout << "Number of days: ";
	cin >> n;

	jul = julian(year, month, day);
	jul = jul - n;

	cout << n << " days before " << month << "/" << day << "/" << year << endl
		<< "it was ";

	jul_to_date(jul, year, month, day);

	cout << month << "/" << day << "/" << year << "." << endl;

	return 0;
}

