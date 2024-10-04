// P214.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string comb,bottom;

	comb = "+--+--+--+\n|  |  |  |\n";
	bottom = "+--+--+--+\n";

	cout << comb << comb << comb << bottom;
	return 0;
}

