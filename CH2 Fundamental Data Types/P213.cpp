// P213.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str_in, str_out;
	int len = 0;

	cout << "Please enter an integer between 1,000 and 999,999: ";
	cin >> str_in;

	len = str_in.length();

	str_out = str_in.substr(0, len - 4) + str_in.substr(len - 3, 3);

	cout << str_out << "\n";
	return 0;
}

