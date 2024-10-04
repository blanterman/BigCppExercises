/* Exercise P9.2. Write a function that computes the alternating sum of all 
elements in a vector. for example, if alternating_sum is called with a vector 
containing

1 4 9 16 9 7 4 9 11

then it computes

1 - 4 + 9 - 16 + 9 - 7 + 4 - 9 + 11 = -2
*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

/**
	Computes the alternating sum of all elements in a vector as defined above
	@param v a vector of floating point values
	@return the alternating sum of the elements in vector v
*/
double alternating_sum(const vector<double>& v)
{
	bool plus = true;
	double alternatingSum = 0;
	for(int i = 0; i < v.size(); i++)
	{
		if(plus)
			alternatingSum += v[i];
		else
			alternatingSum -= v[i];
		plus = !plus;
	}
	return alternatingSum;
}

/* Test Harness */
int main()
{
	int alternatingSum = 0;
	vector<double> v(9);
	v[0] = 1;
	v[1] = 4;
	v[2] = 9;
	v[3] = 16;
	v[4] = 9;
	v[5] = 7;
	v[6] = 4;
	v[7] = 9;
	v[8] = 11;

	alternatingSum = alternating_sum(v);
	if (alternatingSum == -2)
		cout << "Test Passed\n";
	else
		cout << "Test Failed.\nExpected answer: -2.\nYour result: " << alternatingSum << "\n";

	return 0;
}