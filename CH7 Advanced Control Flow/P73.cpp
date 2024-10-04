#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int month = 0;

	cout << "Enter a month: ";
	cin >> month;

	if(month == 2)
	{
		cout << "28 or 29 days.\n";
	}
	else if(month == 4 || month == 6 || month == 9 || month == 11)
	{
		cout << "30 days\n";
	}
	else
	{
		cout << "31 days\n";
	}

	return 0;
}