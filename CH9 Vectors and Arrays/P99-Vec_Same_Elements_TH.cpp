/*	Exercise P9.9. Write a predicate function

bool same_elements(vector<int> a. vector<int> b)

that checks whether two vectors have the same elements in some order, with the 
same multiplicities. For example,

1 4 9 16 9 7 4 9 11

and 

11 1 4 9 16 9 7 4 9

would be considered identical, but 

1 4 9 16 9 7 4 9 11

and

11 11 7 9 16 4 1

would not. You will probably need one or more helper functions.

Bryson Lanterman 20180625
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

/**
	Checks to see if a given value is in a vector and removes it if it is found
	@param value, the value to find
	@param v, the vector in which to look for the value
	@return true if the value was found and false if not
*/

bool find_and_remove(int value, vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
		{
			v.erase(v.begin() + i); // remove the element at index i
			return true;
		}
	}
	return false;
}

/**
	Checks whether two vectors have the smae elements in some order, with the 
	same multiplicities using the following method:

	returns false if vectors have unequal sizes, then creates a copy of the 
	second vector. 

	Iterates through first vector and checks to see if all of its elements can 
	be removed from the copy of the second vector using helper function 
	find_and_remove.

	If an element can't be removed then the element was not contained in the 
	second vector, or that element had a different multiplicity. 

	@param a, a vetcor of integers
	@param b, a vector of integers
	@return true if a and b have the same elements in some order with the same
	mulitiplicities.
*/

bool same_elements(const vector<int>& a, const vector<int>& b)
{
	if (a.size() != b.size())
	{
		return false;
	}

	vector<int> v = b;

	int sizeV = v.size();	// v.size() will change every call of find_and_remove,
							// but we want its original size.
	for (int i = 0; i < sizeV; i++)
	{
		if (!find_and_remove(a[i], v))
		{
			return false;
		}
	}
	return true;
}

/**Test Harness**/
int main()
{
	vector<int> a(9);
	a[0] = 1;
	a[1] = 4;
	a[2] = 9;
	a[3] = 16;
	a[4] = 9;
	a[5] = 7;
	a[6] = 4;
	a[7] = 9;
	a[8] = 11;
	
	vector<int> b(9);
	b[0] = 11;
	b[1] = 1;
	b[2] = 4;
	b[3] = 9;
	b[4] = 16;
	b[5] = 9;
	b[6] = 7;
	b[7] = 4;
	b[8] = 9;
	
	vector<int> c(7);
	c[0] = 11;
	c[1] = 11;
	c[2] = 7;
	c[3] = 9;
	c[4] = 16;
	c[5] = 4;
	c[6] = 1;

	// Test 1 should be true
	if (same_elements(a, b))
	{
		cout << "Test 1 passed\n";
	}
	else
	{
		cout << "Test 1 failed\n";
	}

	// Test 2 should be false
	if (!same_elements(a, c))
	{
		cout << "Test 2 passed\n";
	}
	else
	{
		cout << "Test 2 failed\n";
	}
}