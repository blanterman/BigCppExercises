// P517.cpp : Defines the entry point for the console application.
// Converts a Roman Numeral to an Integer

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/**
	Checks for groups of 4 or more of the same roman numeral
	@param rn string roman numeral
	@return true if there are no groupings of four or more of the same roman numeral
*/
bool rn_4_check(string rn)
{
	int length = rn.length();
	for (int i = 0; i < length - 3; i++)
	{
		if (rn[i] == rn[i + 1] && rn[i + 1] == rn[i + 2] && rn[i + 2] == rn[i + 3])
			return true;
	}
	return false;
}

/**
	Checks that the Roman Numeral combination of letters where the first letter
	is less than the second letter is one of the valid combinations.
	@param rnSub string that is a two letter substring of the roman numeral being checked
	@return true if the combination is valid, false otherwise
*/
bool rn_check(char first, char second)
{
	if (second == 'M' || second == 'D')
	{
		if (first == 'C')
			return true;
	}
	if (second == 'C' || second == 'L')
	{
		if (first == 'X')
			return true;
	}
	if (second == 'X' || second == 'V')
	{
		if (first == 'I')
			return true;
	}
	return false;
}

/**
	Converts a Roman Numeral Character to an integer
	@param rnChar char roman numeral input
	@return integer value equal to the roman numeral input
*/
int rnchar2int(char rnChar)
{
	switch (rnChar)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return 0;
	}
}

/**
	Converts a Roman Mumeral String to an integer by parsing the roman numeral string, searching for errors
	and accumulating the integer equivilant as it goes.
	@param rn string roman numeral input
	@return integer value equal to the roman numeral input
*/
int rn2int(string rn)
{
	// Variables initialized
	int indx = 0;	// Index (of rn) for a while loop iteration. A while loop is used for flexible index control.
	int indx_max = rn.length();	// Index boundary condition for while loop.
	int rnInt = 0;	// Integer equivalent of the roman numeral string

	// Error check: Make sure no character is repeated more than 3 times.
	if (rn_4_check(rn))
		return 0;

	// Case handling when the input is one character long.
	if (indx_max == 1)
		return rnchar2int(rn[0]);	// Returns the converted character

	/* Parses the string and accumulates the integer equivalent by analyzing
	   2 characters at a time. If they fail to covert to an integer using the 
	   rnchar2int function above, then 0 is returned. If the second char is larger
	   than the first, an error check is done on the order in rn_check function 
	   above and 0 is returned on a failure. On a pass the first number is subtracted
	   from the second number and the total is added to the rnInt. If the numbers
	   are equal they are both added to rnInt. If the first is greater than the second,
	   just the first is added to rnInt. The index is moved based on the case as shown.
	*/
	while (indx < indx_max - 1)
	{
		// Grabbing the next two characters and converting them to integers using rnchar2int
		char char1 = rn[indx];
		int int1 = rnchar2int(char1);
		char char2 = rn[indx + 1];
		int int2 = rnchar2int(char2);

		// If the ints are 0 then they failed to find a match and we have an error
		if (int2 == 0 || int1 == 0)
			return 0;

		// case 1: the second roman numeral is greater than the first
		if (int2 > int1)
		{
			if (rn_check(char1, char2)) // Only specific cases are valid
			{
				rnInt += int2 - int1;
				indx += 2;
			}
			else return 0;
		}
		// case 2: the two numbers are equal
		else if (int2 == int1)
		{
			rnInt += int2 + int1;
			indx += 2;
		}
		// case 3: the first number is greater than the second
		else
		{
			rnInt += int1;
			indx++;
		}

	}
	/* Because the while loop was grabbing two letters at a time
	   special cases arise when we reach a last letter that is 
	   not greater than its previous neighbor or is the last in a
	   set of three. In these cases the while loop will kick out 
	   without processing the last letter.
	   Here these cases are handled with the last letter just beint 
	   added to rnInt.
	*/
	if (indx == indx_max - 1)
	{
		char char1 = rn[indx];
		int int1 = rnchar2int(char1);
		rnInt += int1;
	}

	return rnInt;
}
int main()
{
	// Initializing variables
	string rn_str;      // Roman Numeral as a String
	int rn_int = 0;     // Roman Numeral as an Int
	
	// User Prompt to input a Roman Numeral
	cout << "Provide a roman numeral in all caps: ";
	cin >> rn_str;      // User input is stored without error checking

	// String Roman numeral is converted to an Integer using the rn2int function above
	rn_int = rn2int(rn_str);
	
	if (rn_int == 0)    // Error checking will return a zero value if an error is found in the user input
		cout << "input was an invalid roman numeral" << endl;
	else
		cout << rn_str << " equals: " << rn_int << "." << endl;  // prints out results

	return 0;
}

