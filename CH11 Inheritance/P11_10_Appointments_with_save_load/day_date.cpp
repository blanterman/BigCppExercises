/*	This class creates a date object given the passed date information. With 
the date information other information can be calculated (eg day of the week)

Bryson Lanterman 20190304
*/
#include "stdafx.h"
#include "day_date.h"
#include <vector>

date::date()
{
	day = 0;
	month = 0;
	year = 0;
}

date::date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

int date::get_day() const
{
	return day;
}

int date::get_month() const
{
	return month;
}

int date::get_year() const
{
	return year;
}

/**
	Returns true if the given year is a leap year
	@param y year to be tested
	@return true if y is a leap year
*/
bool is_leap(int y)
{
	/* A year is a leap year if it is divisible 
	by 4, unless it is divisible by 100, except 
	when it is divisible by 400 */
	if (y % 4 == 0)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0)
			{
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

/**
	Returns the century code to be used in the 
	calculation of the day of the week from the
	date
	@param y year from which to calculate the 
	century code
	@return century code for the calculation
*/
int centuryCode(int y)
{
	/*
	This century code calculation is established 
	from the fact that century codes repeat every
	400 years and the codes for the 1700s, 1800s,
	1900s and 2000s are 4, 2, 0, 6 respectively.
	*/
	std::vector<int> centCode(4);
	centCode[0] = 6;
	centCode[1] = 4;
	centCode[2] = 2;
	centCode[3] = 0;

	return centCode[((y / 100) % 4)];
}
/**
	Returns the month code to be used in the 
	calculation of the day of the week from the
	date
	@param m month from which to look up the 
	month code
	@return month code for the calculation
*/
int monthCode(int m)
{
	// Month codes are hard coded values
	std::vector<int> monthCode(12);
	monthCode[0] = 1;
	monthCode[1] = 4;
	monthCode[2] = 4;
	monthCode[3] = 0;
	monthCode[4] = 2;
	monthCode[5] = 5;
	monthCode[6] = 0;
	monthCode[7] = 3;
	monthCode[8] = 6;
	monthCode[9] = 1;
	monthCode[10] = 4;
	monthCode[11] = 6;

	return monthCode[m - 1];
}

int date::day_of_week()
{
	/* Calculation for this taken from:
	http://mathforum.org/dr.math/faq/faq.calendar.html 
	*/
	
	// Get the year code from the year
	int yearCode = (year % 100) / 4;

	// Adjust for leap year
	int leapAdjust = 0;
	if (month == 1 || month == 2)
	{
		if (is_leap(year))
		{
			leapAdjust = -1;
		}
	}

	// Get the last two digits of the year
	int yearLastTwo = year % 100;

	/* Calculate the day of the week:
	0 = Saturday
	1 = Sunday
	2 = Monday
	3 = Tuesday
	4 = Wednesday
	5 = Thursday
	6 = Friday
	*/
	return (yearCode + day + monthCode(month) + leapAdjust + centuryCode(year) + yearLastTwo) % 7;
}