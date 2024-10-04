// P218.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	double gal = 0, mpg = 0, dist = 0,
		   num = 0, denom = 0,
		   poss_dist = 0, diff = 0, poss = 0;
	string answer = " not ";

	cout << "Please enter the number of gallons in the tank: ";
	cin >> gal;
	cout << "please enter the fuel efficiency in MPG: ";
	cin >> mpg;
	cout << "Please enter the distance you would like to travel: ";
	cin >> dist;

	poss_dist = gal * mpg;
	diff = poss_dist - dist;
	num = ceil(diff + abs(diff));
	denom = floor(abs(diff) + 1);

	poss = floor(num / denom);

	cout << "You will" << answer.substr(0, 5 - 4 * poss) << "make it.\n";

	return 0;
}

