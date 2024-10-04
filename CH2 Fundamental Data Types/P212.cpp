// P212.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int len = 0, sections = 0, first = 0;
	string number_in, number_out;
	cout << "Please enter an integer >= 1000: ";
	cin >> number_in;

	len = number_in.length();
	sections = (len - 1)/3;
	first = len % 3;

	if (first == 0)
		first = 3;
	
	number_out = number_in.substr(0,first);
	
	for (int i = 0; i < sections; i++)
		number_out = number_out + "," + number_in.substr((i * 3) + first, 3);

	cout << number_out << "\n";

	return 0;
}

