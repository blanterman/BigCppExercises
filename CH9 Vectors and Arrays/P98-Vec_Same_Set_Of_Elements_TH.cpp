/*	Exercise P9.8. Write a predicate function

bool same_set(vector<int> a, vector<int> b)

that checks whether two vectors have the same elements in some order, ignoring 
multiplicities. For example, the two vectors

1 4 9 16 9 7 4 9 11

and 

11 11 7 9 16 4 1

would be considered identical. You will probable need one or more helper 
functions.

Bryson Lanterman 20180622
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

/**
	Iterates over a vector looking for a given value
	@param vec, a vector of ints
	@param val, an int value
	@result true if val is found in vec.
*/

bool found(const vector<int>& vec, int val)
{
	for(int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == val)
			return true;
	}
	return false;
}


/**
	checks whether two vectors have the same elements in some order, ignoring 
	multiplicities using the following method:

	First vector b is checked to see if it contains each of the elements of a 
	at least once.
	Then vector a is checked to see if it contains each of the elements of b 
	at least onece.

	If a has all the elements of b and b has all the elements of a, then a and 
	b have the same elements and multiplicity is ignored.

	@param a, a vector of ints
	@param b, a vector of ints
	@result true if a and b have the same elements in some order, ignoring 
	multiplicities.
*/

bool same_set(const vector<int>& a, const vector<int>& b)
{
	for (int i = 0; i < a.size(); i++)	//Iterate through a looking in b for each element
	{
		if (!found(b, a[i]))
		{
			return false;
		}
	}

	for (int i = 0; i < b.size(); i++)	//Iterate through b looking in a for each element
	{
		if (!found(a, b[i]))
		{
			return false;
		}
	}
	return true;
}

/***Test Harness***/

int main()
{
	//Just use the arrays listed above and then a force fail

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

	vector<int> b(7);
	b[0] = 11;
	b[1] = 11;
	b[2] = 7;
	b[3] = 9;
	b[4] = 16;
	b[5] = 4;
	b[6] = 1;

	vector<int> c(7);
	c[0] = 11;
	c[1] = 11;
	c[2] = 7;
	c[3] = 9;
	c[4] = 17;
	c[5] = 4;
	c[6] = 1;

	//Test 1: Two arrays that have the same elements but not same order or size
	//This should return a true
	if (same_set(a, b))
		cout << "Test 1 passed\n";
	else
		cout << "Test 1 failed\n";

	//Test 2: Two arrays that have different elements
	//This test should return a false;
	if (!same_set(a, c))
		cout << "Test 2 passed\n";
	else
		cout << "Test 2 failed\n";
}