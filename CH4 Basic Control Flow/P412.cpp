// P412.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int year_itgr = 0, thou = 0, hund = 0, tens = 0, ones = 0, idx = 0, over_five = 0;
	string year_rn;

	cout << "Please Enter the year: ";
	cin >> year_itgr;

	// Getting the digits of the year
	ones = year_itgr % 10;
	tens = (year_itgr % 100 - ones) / 10;
	hund = (year_itgr % 1000 - tens - ones) / 100;
	thou = year_itgr / 1000;

	// Printing out to make sure the above worked
	cout << thou << "\n"
		 << hund << "\n"
		 << tens << "\n"
		 << ones << "\n";
	
	// Big if to see if the input is in the right range
	if (year_itgr > 0 && year_itgr <= 3999)
	{
		/* Starts out the RN answer by concatenating the 
		correct number of thousands*/
		while (idx < thou)
		{
			year_rn = year_rn + "M";
			idx++;
		}
		idx = 0; // Reset the while loop index


		// Handles all cases of the for the hundreds  digit
		if (hund <= 3)
		{
			while (idx < hund)
			{
				year_rn = year_rn + "C";
				idx++;
			}
			idx = 0;
		}
		else if (hund == 4)
			year_rn = year_rn + "CD";
		else if (hund >= 5 && hund < 9)
		{
			over_five = hund - 5;
			year_rn = year_rn + "D";
			while (idx < over_five)
			{
				year_rn = year_rn + "C";
				idx++;
			}
			idx = 0;			
		}
		else // hund == 9
			year_rn = year_rn + "CM";


		// Handles all cases of the for the tens  digit
		if (tens <= 3)
		{
			while (idx < tens)
			{
				year_rn = year_rn + "X";
				idx++;
			}
			idx = 0;
		}
		else if (tens == 4)
			year_rn = year_rn + "XL";
		else if (tens >= 5 && tens < 9)
		{
			over_five = tens - 5;
			year_rn = year_rn + "L";
			while (idx < over_five)
			{
				year_rn = year_rn + "X";
				idx++;
			}
			idx = 0;			
		}
		else // tens == 9
			year_rn = year_rn + "XC";

		// Handles all cases of the for the ones digit
		if (ones <= 3)
		{
			while (idx < ones)
			{
				year_rn = year_rn + "I";
				idx++;
			}
			idx = 0;
		}
		else if (ones == 4)
			year_rn = year_rn + "IV";
		else if (ones >= 5 && ones < 9)
		{
			over_five = ones - 5;
			year_rn = year_rn + "V";
			while (idx < over_five)
			{
				year_rn = year_rn + "I";
				idx++;
			}
			idx = 0;			
		}
		else // ones == 9
			year_rn = year_rn + "IX";
	}
	else
	{
		cout << "Error: Improper input range\n";
		return 1;
	}
	cout << "The Roman Numeral Representation is "
		 << year_rn << ".\n";



	return 0;
}

