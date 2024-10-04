// P22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	for (double i = 1; i < 6; i++)
	{
		cout << i << " squared is: " << i * i << "\n";
		cout << i << " cubed is: " << pow(i,3) << "\n";
		cout << i << " to the fourth is: " << pow(i,4) << "\n\n";
	}
	return 0;
}

