// P414.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double num1 = 0, num2 = 0;
	int inum1 = 0, inum2 = 0;
	cout << "Enter two floating Point Numbers: ";
	cin >> num1 >> num2;

	num1 *= 100;
	num2 *= 100;
	
	inum1 = round(num1);
	inum2 = round(num2);

	if (inum1 == inum2)
	{
		cout << "They are the same up to two decimal places.\n";
	}
	else
	{
		cout << "They are different.\n";
	}

    return 0;
}

