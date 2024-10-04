// P516.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/**
	Coverts a digit to a roman numeral
	@param n the integer number to convert
	@param one string representing the ones roman numeral
	@param five string representing the fives roman numeral
	@param ten string representing the tens roman numeral
	@return string representing the roman numeral
*/
string roman_digit(int n, string one, string five, string ten)
{
	string digRN;
	int idx = 0, over_five = 0;
	if (n <= 3)
		{
			while (idx < n)
			{
				digRN = digRN + one;
				idx++;
			}
			idx = 0;
		}
		else if (n == 4)
			digRN = digRN + one + five;
		else if (n >= 5 && n < 9)
		{
			over_five = n - 5;
			digRN = digRN + five;
			while (idx < over_five)
			{
				digRN = digRN + one;
				idx++;
			}
			idx = 0;			
		}
		else // n == 9
			digRN = digRN + one + ten;
		return digRN;
}

int main()
{
	int n = 0;
	string nRN, roman_ones, roman_tens, roman_hundreds, roman_thousands;

	cout << "Please Enter the year: ";
	cin >> n;

	if (n > 0 && n <= 3999)
	{
		roman_ones = roman_digit(n % 10, "I", "V", "X");
		n = n / 10;
		roman_tens = roman_digit(n % 10, "X", "L", "C");
		n = n / 10;
		roman_hundreds = roman_digit(n % 10, "C", "D", "M");
		n = n / 10;
		roman_thousands = roman_digit(n % 10, "M", " ", " ");
	}
	else
	{
		cout << "Error: Improper input range\n";
		return 1;
	}
	nRN = roman_thousands + roman_hundreds + roman_tens + roman_ones;
	cout << "The Roman Numeral Representation is "
		 << nRN << ".\n";
	return 0;
}

