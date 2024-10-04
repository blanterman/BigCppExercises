/*	Write a predicate function

bool equals(vector<int> a, vector<int> b)

that checks whether two vectors have the same elements in the same order.

Bryson Lanterman 20180622
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

/**
	Checks whether two vectors have the same elements in the same order
	@param a, a vector of ints
	@param b, a vector of ints
	@return bool true if the vectors have same elements in same order
*/
bool equals(vector<int> a, vector<int> b)
{
	if (a.size() != b.size())
		return false;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}

	return true;
}

/* ** Test Harness ** */
int main() 
{
	vector<int> a(5);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	vector<int> b(4);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	b[3] = 4;
	vector<int> c(5);
	c[0] = 1;
	c[1] = 2;
	c[2] = 3;
	c[3] = 4;
	c[4] = 6;
	vector<int> d(5);
	d[0] = 1;
	d[1] = 2;
	d[2] = 3;
	d[3] = 4;
	d[4] = 5;

	// Test 1: Different size vectors
	if (!equals(a, b))
	{
		cout << "Test 1: Passed. The function returns a false for vectors of\n"
			 << "unequal length\n";
	}
	else
	{
		cout << "Test 1: Failed. The function returns a true for vectors of\n"
			 << "unequal length\n";
	}
	// Test 2: Same size vectors, with different elements
	if (!equals(a, c))
	{
		cout << "Test 2: Passed. The function returns a false for vectors with\n"
			 << "unequal elements or elements in wrong order\n";
	}
	else
	{
		cout << "Test 2: Failed. The function returns a true for vectors with\n"
			 << "unequal elements or elements in wrong order\n";
	}
	// Test 3: Equal vectors
	if (!equals(a, d))
	{
		cout << "Test 3: Failed. The function returns a false for vectors of\n"
			 << "equal elements in the same order\n";
	}
	else
	{
		cout << "Test 3: passed. The function returns a true for vectors of\n"
			 << "equal elements in the same order\n";
	}
	return 0;
}