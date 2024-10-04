#include "stdafx.h"
#include "Grade.h"
#include <iostream>

using namespace std;

Grade::Grade()
{
}

Grade::Grade(string g)
{
	grade = g;
}

double Grade::convert() const
{
	string input, letter, sign;
	double gpa = 0;
	bool has_sign = false;

	if (grade.length() > 2)
	{
		return 6.0;
	}

	letter = grade.substr(0,1);
	if (grade.length() == 2)
	{
		has_sign = true;
		sign = grade.substr(1,1);
	}

	if (letter == "A")
		gpa = 4.0;
	else if (letter == "B")
		gpa = 3.0;
	else if (letter == "C")
		gpa = 2.0;
	else if (letter == "D")
		gpa = 1.0;
	else if (letter == "F")
		gpa = 0.0;
	else
	{
		return 7.0;
	}

	if (has_sign)
	{
		if (sign == "+")
			gpa += 0.3;
		else if (sign == "-")
			gpa -= 0.3;
		else
		{
			return 8.0;
		}
	}

	if (gpa > 4.0)
		gpa = 4.0;
	if (gpa == 0.3)
		gpa = 0.0;
	if (gpa < 0.0)
		gpa = 0.0;

	return gpa;
}