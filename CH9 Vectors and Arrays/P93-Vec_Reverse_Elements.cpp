/* Exercise P9.3. Write a procedure reverse that reverses the sequence of 
elements in a vector. For example, if reverse is called with a vector 
containing

1 4 9 16 9 7 4 9 11

then the vector is changed to 

11 9 4 7 9 16 9 4 1
*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

/**
	reverses the sequence of elements in a vector of known size
	@param v a vector with floating point elements
*/
void reverse(vector<double>& v)
{
	vector<double> temp(v.size());
	int vIndex = v.size() - 1;
	for (int i = 0; i < v.size(); i++)
	{
		temp[vIndex] = v[i];
		vIndex--;
	}
	v = temp;
}

/**
	reverses the sequence of elements in a vector of unknown size (less efficient)
	@param v a vector with floating point elements
*/
void reverse2(vector<double>& v)
{
	vector<double> temp;
	for (int i = v.size() - 1; i = 0; i--)
	{
		temp.push_back(v[i]);
	}
	v = temp;
}

/*** TEST HARNESS ***/

int main()
{
	bool same = true;
	vector<double> v(9);
	vector<double> vRev(9);

	/******* Test 1 Begin *******/
	v[0] = 1;
	v[1] = 4;
	v[2] = 9;
	v[3] = 16;
	v[4] = 9;
	v[5] = 7;
	v[6] = 4;
	v[7] = 9;
	v[8] = 11;

	
	vRev[0] = 11;
	vRev[1] = 9;
	vRev[2] = 4;
	vRev[3] = 7;
	vRev[4] = 9;
	vRev[5] = 16;
	vRev[6] = 9;
	vRev[7] = 4;
	vRev[8] = 1;

	reverse(v);

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != vRev[i])
			same = false;
	}
	if (same)
		cout << "Test 1 Passed\n";
	else
		cout << "Test 1 Failed\n";
	/******* Test 1 End *******/

	/******* Test 2 Begin *******/
	same = true;
	v[0] = 1;
	v[1] = 4;
	v[2] = 9;
	v[3] = 16;
	v[4] = 9;
	v[5] = 7;
	v[6] = 4;
	v[7] = 9;
	v[8] = 11;

	vRev[0] = 11;
	vRev[1] = 9;
	vRev[2] = 4;
	vRev[3] = 7;
	vRev[4] = 9;
	vRev[5] = 16;
	vRev[6] = 9;
	vRev[7] = 4;
	vRev[8] = 1;

	reverse2(v);

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != vRev[i])
			same = false;
	}
	if (same)
		cout << "Test 2 Passed\n";
	else
		cout << "Test 2 Failed\n";
	/******* Test 2 End *******/

	return 0;
}