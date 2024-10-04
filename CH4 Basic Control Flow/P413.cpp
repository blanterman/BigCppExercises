// P413.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name1, name2, name3, name;
	cout << "Enter 3 strings: ";
	cin >> name1 >> name2 >> name3;

	if (name3 < name2)
	{
		name = name2;
		name2 = name3;
		name3 = name;

	}
	if (name2 < name1)
	{
		name = name1;
		name1 = name2;
		name2 = name;

	}
	if (name3 < name2)
	{
		name = name2;
		name2 = name3;
		name3 = name;
	}

	cout << name1 << "\n"
		<< name2 << "\n"
		<< name3 << "\n";


    return 0;
}

