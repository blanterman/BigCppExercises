#include "stdafx.h"
#include <iostream>
#include <cfloat>

using namespace std;

int main()
{
	double input = 0;
	double max = 0, min = DBL_MAX, avg = 0, count = 0, sum = 0;
	while(cin >> input)
	{
		count++;
		if (input > max)
		{
			max = input;
		}
		if (input < min)
		{
			min = input;
		}
		sum += input;
	}
	avg = sum/count;

	cout << "Max: " << max << "\nMin: " << min << "\nAverage: " << avg << "\n";
	return 0;
}