// P221.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const string LETTER_H = "*   *\n*   *\n*****\n*   *\n*   *\n\n\n";
const string LETTER_E = "*****\n*    \n**** \n*    \n*****\n\n\n";
const string LETTER_L = "*    \n*    \n*    \n*    \n*****\n\n\n";
const string LETTER_O = " *** \n*   *\n*   *\n*   *\n *** \n\n\n";

int main()
{
	cout << LETTER_H << LETTER_E << LETTER_L << LETTER_L << LETTER_O;
	return 0;
}

