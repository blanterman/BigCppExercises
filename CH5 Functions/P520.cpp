// P519.cpp : Defines the entry point for the console application.
//
#include "ccc_win.h"
#include <iostream>
#include <string>

using namespace std;

/**
	prints a half bar at the given point
	@param start Point where the half bar starts
*/
void half_bar(Point start)
{
	Point p2 = start;
	p2.move(0.0, 0.5);
	Line l1(start, p2);
	cwin << l1;
}

/**
	prints a full bar at the given point
	@param start Point where the full bar starts
*/
void full_bar(Point start)
{
	Point p2 = start;
	p2.move(0.0, 1.0);
	Line l1(start, p2);
	cwin << l1;
}

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
void zip2bar(int zip)
{
	double beg = -7.75, interval = 0.5;
	double curr = beg;
	int check =  zipcheck(zip);

	full_bar(Point(curr,0.0));
	curr += interval;

	string zipstr = to_string(static_cast<long long>(zip));
	string checkstr = to_string(static_cast<long long>(check));
	zipstr = zipstr + checkstr;
	for(int i = 0; i < zipstr.length(); i++)
	{
		int dig = stoi(zipstr.substr(i,1),nullptr);
		switch (dig)
		{
		case 1:
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			break;
		case 2:
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			break;
		case 3:
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			break;
		case 4:
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			break;
		case 5:
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			break;
		case 6:
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			break;
		case 7:
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			break;
		case 8:
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			break;
		case 9:
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			break;
		default:
			full_bar(Point(curr, 0.0));
			curr += interval;
			full_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			half_bar(Point(curr, 0.0));
			curr += interval;
			break;
		}
	}
	full_bar(Point(curr, 0.0));
	curr += interval;
	
}


int ccc_win_main()
{
	int zip = 0;
	zip = cwin.get_int("Enter the zip code: ");
	zip2bar(zip);	
	return 0;
}

