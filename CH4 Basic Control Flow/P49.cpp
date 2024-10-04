// P49.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string resp;
	cout << "Do you want to continue?";
	cin >> resp;

	if (resp == "Y" || resp == "y" || resp == "Yes" || resp == "yes" || resp == "OK" || resp == "Sure" || resp == "Why not?")
	{
		cout << "OK\n";
	}
	else if (resp == "n" || resp == "N" || resp == "No" || resp == "NO" || resp == "no")
	{
		cout << "Terminating\n";
	}
	else
	{
		cout << "Bad Input\n";
	}
	return 0;
}

