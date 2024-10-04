// P521.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/**
	Converts a barcode representation of an integer digit to the base ten representation
	using the following convention:
	Each digit of the zip code, and the check digit, is encoded according to the following 
	table where 0 denotes a half bar and 1 a full bar.
	
	  | 7 | 4 | 2 | 1 | 0 
	-----------------------
	1 | 0 | 0 | 0 | 1 | 1
	2 | 0 | 0 | 1 | 0 | 1
	3 | 0 | 0 | 1 | 1 | 0
	4 | 0 | 1 | 0 | 0 | 1
	5 | 0 | 1 | 0 | 1 | 0
	6 | 0 | 1 | 1 | 0 | 0
	7 | 1 | 0 | 0 | 0 | 1
	8 | 1 | 0 | 0 | 1 | 0
	9 | 1 | 0 | 1 | 0 | 0
	0 | 1 | 1 | 0 | 0 | 0
	
	Note that they represent all combinations of two full and three half bars. The digit can be
	easily computed from the bar code using the comumn weights 7, 4, 2, 1, 0. For example, 
	01100 is 0 x 7 + 1 x 4 + 1 x 2 0 x 1 + 0 x 0 = 6. the only exception is 0, which would 
	yield 11 according to the weight formula.

	@param bcdig string barcode digit
	@return num integer value of digit in base ten
*/
int bcd2int(string bcdig)
{
	int num = 0;
	
	// number is a sum according to weight formula by position
	if (bcdig[0] == '|')
		num += 7;
	if (bcdig[1] == '|')
		num += 4;
	if (bcdig[2] == '|')
		num += 2;
	if (bcdig[3] == '|')
		num += 1;

	// Handle exception to weight formula
	if (num == 11)
		return 0;

	// Error checking that input is in valid range
	if (num > 9 || num == 0)
		return -1;

	return num;
}

/**
	Converts a bar code string to an integer zip code
	@param barcode string bar code
	@return zip integer zipcode
*/
int bc2zip(string barcode)
{
	string strzip;
	int bclen = barcode.length();
	int sum = 0, zip = 0;
	
	/* Error checking on the barcode:
		1) Checking that the ends are long bars
		2) Checking that each of the digits are represented by 5 chars
	*/
	if (barcode[0] != '|' || barcode[bclen - 1] != '|')
		return 0;
	if ((bclen - 2) % 5 != 0) //Num of characters minus ends must be divisible by 5
		return 0;

	// Iterates through the barcode 5 chars at a time.
	for (int i = 1; i < barcode.length() - 1; i += 5) 
	{
		// Translates short and long bars to a number
		int idig = bcd2int(barcode.substr(i,4)); // Only 4 chars passed because last is '0' and is not needed

		// Error checking: The function will return -1 if there was an error
		if (idig == -1)
			return 0;

		/*This sum is used for error checking
		  because the last digit of the bar code is a check sum digit.
		  With that digit added in, the sum should be divisible by 10 evenly
		*/ 
		sum += idig;

		// Using concatenation to assemble the string representation of the integer zip
		strzip = strzip + to_string(static_cast<long long>(idig));
	}

	// Error checking that the checksum digit was correct
	if (sum % 10 != 0)
		return 0;

	// Remove the checksum digit (the last digit)
	strzip.erase(strzip.length() - 1, 1);

	// Convert from string to an integer
	zip = stoi(strzip,nullptr);
	
	return zip;
}

int main()
{
	// ||:|:::|:|:||::::::||:|::|:::|||   should be 95014
	// ||:|::::|:|||:::::|:|:|:|:::|:||   should be 92025
	// ||:|::||:::::|:|:::||||:::|::|:|   should be 90210

	int zip = 0;
	string bc;

	cout << "Please provide a bar code to read: ";
	cin >> bc;

	// Turn the string barcode into an integer zipcode
	zip = bc2zip(bc);
	
	if (zip == 0) // All errors are handles in the functions and will return a zero.
		cout << "Improper bar code was entered" << endl;
	else
		cout << "The bar code entered is zip code: " << zip << endl;
	
	return 0;
}

