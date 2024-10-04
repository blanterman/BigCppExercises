// P411.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	double grade = 0;
	string letter;

	cout << "Enter the numerical grade value: ";
	cin >> grade;

	if (grade <= 4.0 && grade >= 0)
	{
		if (grade >= 3.85)
			letter = "A";
		if (grade < 3.85 && grade >= 3.50)
			letter = "A-";
		if (grade < 3.50 && grade >= 3.15)
			letter = "B+";
		if (grade < 3.15 && grade >= 2.85)
			letter = "B";
		if (grade < 2.85 && grade >= 2.50)
			letter = "B-";
		if (grade < 2.50 && grade >= 2.15)
			letter = "C+";
		if (grade < 2.15 && grade >= 1.85)
			letter = "C";
		if (grade < 1.85 && grade >= 1.50)
			letter = "C-";
		if (grade < 1.50 && grade >= 1.15)
			letter = "D+";
		if (grade < 1.15 && grade >= 0.85)
			letter = "D";
		if (grade < 0.85 && grade >= 0.35)
			letter = "D-";
		if (grade < 0.35)
			letter = "F";

		cout << "The letter grade is: " << letter << ".\n";
	}



	return 0;
}

