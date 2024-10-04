// P513.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/**
	Checks if a year is a leap year
	@param year integer year
	@return true if the year is a leap year
*/
bool leap_year(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			return false;
		}
		return true;
	}
	return false;
}

int main()
{
	int year = 0;
	
	cout << "Enter year to test if it is a leap year: ";
	
	cin >> year;

	if (leap_year(year))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}