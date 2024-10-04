// P410.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input, letter, sign;
	double grade = 0;
	bool has_sign = false;

	cout << "Enter a letter grade:";
	cin >> input;

	if (input.length() > 2)
	{
		cout << "Improper input\n";
		return 1;
	}

	letter = input.substr(0,1);
	if (input.length() == 2)
	{
		has_sign = true;
		sign = input.substr(1,1);
	}

	if (letter == "A")
		grade = 4.0;
	else if (letter == "B")
		grade = 3.0;
	else if (letter == "C")
		grade = 2.0;
	else if (letter == "D")
		grade = 1.0;
	else if (letter == "F")
		grade = 0.0;
	else
	{
		cout << "Improper input\n";
		return 2;
	}

	if (has_sign)
	{
		if (sign == "+")
			grade += 0.3;
		else if (sign == "-")
			grade -= 0.3;
		else
		{
			cout << "Improper input\n";
			return 3;
		}
	}

	if (grade > 4.0)
		grade = 4.0;
	if (grade == 0.3)
		grade = 0.0;
	if (grade < 0.0)
		grade = 0.0;
	
	cout << "The numberic value is " << grade << ".\n";

	return 0;
}

