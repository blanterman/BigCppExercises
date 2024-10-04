#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int year = 0;

	cout << "Pleas provide a year greater than or equal to 0: ";
	cin >> year;
	
	if(year < 0)
		cout << "Not a valid year\n";
	else if(year <= 1582)
	{
		if(year % 4 == 0)
			cout << "Leap year\n";
		else
			cout << "Not a leap year\n";
	}
	else
	{
		if(year % 4 == 0 && year % 100 == 0)
		{
			if(year % 400 == 0)
				cout << "Leap year\n";
			else
				cout << "Not a leap year\n";
		}
		else if(year % 4 == 0)
			cout << "Leap year\n";
		else
			cout << "Not a leap year\n";
	}
	return 0;
}