// P222.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const string MONTHS = "January  February March    April    May      June     July     August   SeptemberOctober  November December ";
const int LENGTH = 9;

int main()
{
	int input = 0, indx = 0;
	cout << "Please enter the month number: ";
	cin >> input;

	indx = (input - 1) * LENGTH;

	cout << "The month corresponding to that number is: "
		 << MONTHS.substr(indx, LENGTH) << "\n";

	return 0;
}

