// P511.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/**
	Displays a prompt string, followed by a space, reads a floating-point number in, and returns it.
	@param string prompt for obtaining a double value
	@return floating point
*/
double get_double(string prompt)
{
	double resp = 0;
	cout << prompt << " ";
	cin >> resp;
	if (cin.fail())
		exit(1);
	else
		return resp;
}

int main()
{
	double salary = 0;
	salary = get_double("Please enter salary.");
	cout << "you entered: " << salary << endl;
	return 0;
}

