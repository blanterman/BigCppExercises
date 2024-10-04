// P46.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double next, highest;
	cout << "Please enter three numbers: ";	
	cin >> highest;	
	cin >> next;
	if (next > highest)
		highest = next;
	cin >> next;
	if (next > highest)
		highest = next;	

	cout << "The Largest Number is: " << highest << ".\n";

	return 0;
}

