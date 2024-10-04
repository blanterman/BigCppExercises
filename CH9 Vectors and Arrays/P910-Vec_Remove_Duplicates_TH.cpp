/*	Write a function that removes duplicates from a vector. For example, if 
remove_duplicates is called with a vector containing

1 4 9 16 9 7 4 9 11

then the vector is chanege to 

1 4 9 16 7 11

Bryson Lanterman 201806025
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

/**
	removes duplicate entries from a vector using the following method:
	
	Starts at the second element ends at the last element.
	
	Looks at the previous elements for a match.
	
	If a match is found, the current element is deleted and all following 
	elements shift to the left.
	
	When an element is deleted and a shift occurs, the same index is used for 
	the next element to be checked.

	@param v vector with potential duplicates
*/
void remove_duplicates(vector<int>& v)
{
	for (int i = 1; i < v.size(); i++)	// Start at first element end at last
	{
		for (int j = 0; j < i; j++)		// Search all previous elements
		{
			if (v[j] == v[i])			// Match found condition
			{
				v.erase(v.begin() + i); // Remove ith element and shift to left
				i--;					// Adjust index for the shift.
			}
		}
	}
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

	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << "\n";

	remove_duplicates(a);

	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}