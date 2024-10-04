// P424.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	int count = 0;
	double dp = 0, sum = 0, sumsq = 0, stdev = 0, sq_sum = 0, avg = 0;
	string iline;
	bool more = true;

	cout << "Enter Data for Processing: ";
	getline(cin, iline);
	stringstream ss(iline);

	while (more)
	{
		ss >> dp;
		if (ss.fail())
		{
			more = false;
			if (ss.eof())
				cout << "Data Successfully Parsed.\n";
			else
			{
				cout << "Bad data\n";
				return 1;
			}
		}
		else
		{
			count++;
			sum += dp;
			sumsq += dp * dp;
		}
	}
	avg = sum / static_cast<double>(count);
	sq_sum = sum * sum;
	stdev = sqrt((sumsq - ((1.0/static_cast<double>(count)) * sq_sum))/(static_cast<double>(count) - 1.0));

	cout << "Count of values: " << count << "\n"
		<< "Average of values: " << avg << "\n"
		<< "Standard Deviation: " << stdev << "\n";
	return 0;
}

