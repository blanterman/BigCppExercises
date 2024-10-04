// P519.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/**
	Gets the check digit of a zip code. A check digit is the value that would be needed
	to be added to the sum of the digits of a zip code to make it evenly divisible by 10.
	@param zip integer zip code
	@return check integer check value
*/
int zipcheck(int zip)
{
	int sum = 0, check = 0;
	string zipstr = to_string(static_cast<long long>(zip)); // converts the zip code to a string for iteration
	// Iterates through the zip code digits and adds them up.
	for(int i = 0; i < zipstr.length(); i++)
	{
		int dig = stoi(zipstr.substr(i,1),nullptr);
		sum += dig;
	}
	check = 10 - (sum % 10); // Computes the check digit for the bar code
	return check;
}

/**
	Converts a five digit zip code to a postal bar code
	@param zip integer value representing a zip code
	@return bc string postal bar code
*/
string zip2bar(int zip)
{
	int check =  zipcheck(zip);
	string bar = "|";
	string zipstr = to_string(static_cast<long long>(zip));
	string checkstr = to_string(static_cast<long long>(check));
	zipstr = zipstr + checkstr;
	for(int i = 0; i < zipstr.length(); i++)
	{
		int dig = stoi(zipstr.substr(i,1),nullptr);
		switch (dig)
		{
		case 1:
			bar = bar + ":::||";
			break;
		case 2:
			bar = bar + "::|:|";
			break;
		case 3:
			bar = bar + "::||:";
			break;
		case 4:
			bar = bar + ":|::|";
			break;
		case 5:
			bar = bar + ":|:|:";
			break;
		case 6:
			bar = bar + ":||::";
			break;
		case 7:
			bar = bar + "|:::|";
			break;
		case 8:
			bar = bar + "|::|:";
			break;
		case 9:
			bar = bar + "|:|::";
			break;
		default:
			bar = bar + "||:::";
			break;
		}
	}
	bar = bar + "|";
	return bar;
}


int main()
{
	int zip = 0;
	string zipstr;
	cout << "Enter the zip code: ";
	cin >> zip;
	zipstr = zip2bar(zip);
	cout << "That zip code would be this bar code:\n"
		 << zipstr << endl;

	return 0;
}

