/*	Exercise P9.6. Write a function

vector<int> merge_sorted(vector<int> a, vector<int> b)

that merges two sorted vectors, producing a new sorted vector. Keep an index 
into each vector, indicating how much of it has been processed already. Each 
time, append the smallest unprocessed element from either vector, then advance 
the index. for example, if a is 

1 4 9 16

and b is

4 7 9 9 11

then merge_sorted returns the vecotr 

1 4 4 7 9 9 9 11 16

Bryson Lanterman 20 June 2018
*/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

/**
	Merges two sorted vectors producing a sorted vector
	@param a, a sorted vector
	@param b, a sorted vector
	@return c, a sorted vector from merging a and b
*/
vector<int> merge_sorted(vector<int> a, vector<int> b)
{
	vector<int> c(a.size() + b.size());
	int aIndex = 0;
	int bIndex = 0;
	bool aEmpty = false;
	bool bEmpty = false;
	
	for (int i = 0; i < c.size(); i++)
	{
		if (aIndex == a.size())
			aEmpty = true;
		if (bIndex == b.size())
			bEmpty = true;
		if (!aEmpty && !bEmpty)
		{
			if (a[aIndex] <= b[bIndex])
			{
				c[i] = a[aIndex];
				aIndex++;
			}
		
			else
			{
				c[i] = b[bIndex];
				bIndex++;
			}
		}
		if (aEmpty && !bEmpty)
		{
			c[i] = b[bIndex];
			bIndex++;
		}
		if (!aEmpty && bEmpty)
		{
			c[i] = a[aIndex];
			aIndex++;
		}
	}
	return c;
}

/*  Test Harness  */

int main()
{
	vector<int> a(4);
	a[0] = 1;
	a[1] = 4;
	a[2] = 9;
	a[3] = 16;

	vector<int> b(5);
	b[0] = 4;
	b[1] = 7;
	b[2] = 9;
	b[3] = 9;
	b[4] = 11;

	vector<int> cee(9);
	cee[0] = 1;
	cee[1] = 4;
	cee[2] = 4;
	cee[3] = 7;
	cee[4] = 9;
	cee[5] = 9;
	cee[6] = 9;
	cee[7] = 11;
	cee[8] = 16;

	vector<int> c = merge_sorted(a,b);

	bool pass = true;

	for (int i = 0; i < c.size(); i++)
	{
		if (c[i] != cee[i])
			pass = false;
	}
	if (pass)
		cout << "test passed\n";
	else
		cout << "test failed\n";
	return 0;
}