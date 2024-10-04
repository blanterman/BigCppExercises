// P14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Non floating point:\n"
		 << "Product of Integers 1 to 10 = \n"
		 << 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 << "\n\n"
		 << "Product of reciprocals of first ten integers using int division:\n"
		 << 1/1 * 1/2 * 1/3 * 1/4 * 1/5 * 1/6 * 1/7 * 1/8 * 1/9 * 1/10 << "\n\n"
		 << "Now using floating point division:\n"
		 << 1.0/1.0 * 1.0/2.0 * 1.0/3.0 * 1.0/4.0 * 1.0/5.0 * 1.0/6.0 * 1.0/7.0 * 1.0/8.0 * 1.0/9.0 * 1.0/10.0 << "\n\n";
	return 0;
}

