// P215.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input, output;
	int len = 0;

	cout << "Please enter any integer: ";
	cin >> input;

	len = input.length();

	output = input.substr(0, 1);

	for (int i = 1; i < len; i++)
	{
		output = output + " " + input.substr(i, 1);
	}

	cout << output << "\n";
    return 0;
}

